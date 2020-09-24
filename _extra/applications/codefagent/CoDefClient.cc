/*
 * CoDefClient.cc
 *
 *  Created on: 2020Äê8ÔÂ31ÈÕ
 *      Author: bjche
 */

#include "inet/_extra/applications/codefagent/CoDefClient.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/L3AddressResolver.h"

namespace inet{

using namespace std;

Define_Module(CoDefClient);

void CoDefClient::initialize(int stage){
    TcpAppBase::initialize(stage);
}

void CoDefClient::finish(){
    TcpAppBase::finish();
}

void CoDefClient::refreshDisplay() const{
    TcpAppBase::refreshDisplay();

}

void CoDefClient::handleStartOperation(LifecycleOperation *operation)
{
    generateCuid();
    if (simTime() <= tOpen) {
        timeoutMsg->setKind(MSGKIND_CONNECT);
        scheduleAt(tOpen, timeoutMsg);
    }
}

void CoDefClient::handleStopOperation(LifecycleOperation *operation)
{
    cancelEvent(timeoutMsg);
    if (socket.isOpen())
        close();
    delayActiveOperationFinish(par("stopOperationTimeout"));
}

void CoDefClient::handleCrashOperation(LifecycleOperation *operation)
{
    cancelEvent(timeoutMsg);
    /*if (operation->getRootModule() != getContainingNode(this))
        socket.destroy();*/
}

void CoDefClient::handleTimer(cMessage *msg)
{
    switch (msg->getKind()) {
        case MSGKIND_CONNECT:
            if (true)
                connect(); // sending will be scheduled from socketEstablished()
            else
                throw cRuntimeError("TODO");
            break;

        case MSGKIND_ON:

            break;

        case MSGKIND_CLOSE:
            close();
            break;

        default:
            throw cRuntimeError("Invalid timer msg: kind=%d", msg->getKind());
    }
}

void CoDefClient::socketEstablished(TcpSocket *socket){
    TcpAppBase::socketEstablished(socket);
    timeoutMsg->setKind(MSGKIND_ON);
    //simtime_t tSend = commands[commandIndex].tSend;
    scheduleAt(std::max(tSend, simTime()), timeoutMsg);
}
void CoDefClient::socketDataArrived(TcpSocket *socket, Packet *msg, bool urgent){
    packetsRcvd++;
    bytesRcvd += msg->getByteLength();
    emit(packetReceivedSignal, msg);
    processPacket();
}

void CoDefClient::socketClosed(TcpSocket *socket){
    TcpAppBase::socketClosed(socket);
    cancelEvent(timeoutMsg);
    if (operationalState == State::STOPPING_OPERATION && !this->socket.isOpen())
        startActiveOperationExtraTimeOrFinish(par("stopOperationExtraTime"));
}
void CoDefClient::socketFailure(TcpSocket *socket, int code){
    TcpAppBase::socketFailure(socket, code);
    cancelEvent(timeoutMsg);
}



void CoDefClient::generateCuid(){
    cuid = to_string(getSimulation()->getUniqueNumber());
    //Encryption TBD
}

void CoDefClient::processPacket(){

}

void CoDefClient::regist(){
    auto header = makeShared<CoDefRequestHeader>();
    header->setHeader(POST);
    header->insertUriPath("CoDef");
    header->insertUriPath("Client");
    Packet * pkt = new Packet("CoDefClient Register");
    pkt->insertAtFront(header);
    socket.send(pkt);
}

void CoDefClient::unregist(){
    auto header = makeShared<CoDefRequestHeader>();
    header->setHeader(DEL);
    header->insertUriPath("CoDef");
    header->insertUriPath("Client");
    string tmp = "cuid=" + cuid;
    header->insertUriPath(tmp.c_str());
    Packet * pkt = new Packet("CoDefClient UnRegister");
    pkt->insertAtFront(header);
    socket.send(pkt);
}

void CoDefClient::sendHeartBeat(){
    auto header = makeShared<CoDefRequestHeader>();
    header->setHeader(PUT);
    header->insertUriPath("CoDef");
    header->insertUriPath("HeartBeat");
    string tmp ="peerHbStatus:"+ to_string(peerHbStatus);
    header->insertUriPath(tmp.c_str());
    Packet * pkt = new Packet("CoDefClient HeartBeat");
    pkt->insertAtFront(header);
    socket.send(pkt);
}

void CoDefClient::sendMitigationRequest(RequestType reqType, int mid){
    if( (!registered) || cuid.length() == 0){
        EV << "sendMitigationRequest() : Not Registered! No message will be sent";
        return ;
    }
    switch(reqType){
    case GET:{
        //Mitigation Query
        auto header = makeShared<CoDefRequestHeader>();
        header->setHeader(GET);
        header->insertUriPath("CoDef");
        header->insertUriPath("Mitigation");
        string tmp = "cuid=" + cuid;
        header->insertUriPath(tmp.c_str());
        if(mid != -1){//specific query
            string tmp = "mid=" + to_string(mid);
            header->insertUriPath(tmp.c_str());
        }
        Packet * pkt = new Packet("CoDefClient Mitigation Query");
        pkt->insertAtFront(header);
        socket.send(pkt);
        break;
    }
    case PUT:{
        EV_INFO << "sendMitigationRequest() : Wrong parameter! Mitigation Target needed";
        break;
    }
    case DEL:{
        //Mitigation Delete
        if(mid == -1){
            EV_INFO << "sendMitigationRequest() : Wrong parameter! Mid needed";
        }
        auto header = makeShared<CoDefRequestHeader>();
        header->setHeader(DEL);
        header->insertUriPath("CoDef");
        header->insertUriPath("Mitigation");
        string tmp = "cuid=" + cuid;
        header->insertUriPath(tmp.c_str());
        tmp = "mid=" + to_string(mid);
        header->insertUriPath(tmp.c_str());
        break;
    }
    default:{
        EV_INFO << "sendMitigationRequest() : Wrong reqType!";
        return ;
    }
    }
}

void CoDefClient::sendMitigationRequest(RequestType reqType, int mid, bool attackStatus){
    if(reqType != PUT || mid == -1 ){
        EV_INFO << "sendMitigationRequest() : Wrong parameter! Check reqType and mid!";
        return ;
    }
    //Mitigation Efficacy Update
    auto header = makeShared<CoDefRequestHeader>();
    header->setHeader(GET);
    header->insertUriPath("CoDef");
    header->insertUriPath("Mitigation");
    string tmp = "cuid=" + cuid;
    header->insertUriPath(tmp.c_str());
    tmp = "mid=" + to_string(mid);
    header->insertUriPath(tmp.c_str());

    auto payload = makeShared<MitigationEfficacy>();
    payload->setAttackStatus(attackStatus);

    Packet * pkt = new Packet("CoDefClient Mitigation Efficacy Update");
    pkt->insertAtFront(header);
    pkt->insertAtBack(payload);
}

void CoDefClient::sendMitigationRequest(Request reqType, int mid, MitigationTarget *target , int lifetime, bool triggerMitigation){
    /*if(reqType != PUT || mid != -1){
        EV_INFO << "sendMitigationRequest() : Wrong parameter! Check reqType and mid!";
        return ;
    }*/
    //Mitigation Create
}

void CoDefClient::sendFilterRuleRequest(string fliterRule){

}


}
