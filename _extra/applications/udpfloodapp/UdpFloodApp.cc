/*
 * MyApp.cc
 *
 *  Created on: 2020Äê8ÔÂ27ÈÕ
 *      Author: bjche
 */

#include "../../applications/udpfloodapp/UdpFloodApp.h"

#include "inet/applications/base/ApplicationPacket_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/lifecycle/LifecycleOperation.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/L3AddressResolver.h"

#include <iostream>

namespace inet{
using std::cout;

Define_Module(UdpFloodApp);

UdpFloodApp::UdpFloodApp(){
}

UdpFloodApp::~UdpFloodApp(){
    cancelAndDelete(selfMsg);
}

void UdpFloodApp::initialize(int stage){
    ApplicationBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        WATCH(numSent);
        startTime = par("startTime");
        stopTime = par("stopTime");
        destPort = par("destPort");
        packetName = par("packetName");
        numSent = 0;
        selfMsg = new cMessage("sendTimer");

        if (stopTime >= 0.0 && stopTime < startTime)
            throw cRuntimeError("Invalid startTime/stopTime parameters");
    }
}

void UdpFloodApp::finish(){
    recordScalar("packets sent", numSent);
    ApplicationBase::finish();
}

void UdpFloodApp::processStart(){
    socket.setOutputGate(gate("socketOut"));
    const char *localAddr = par("localAddr");
    socket.bind(*localAddr ? L3AddressResolver().resolve(localAddr) : L3Address(), localPort);
    socket.setCallback(this);

    const char *destAddrs = par("destAddr");
    cStringTokenizer tokenizer(destAddrs);
    const char *token;

    while ((token = tokenizer.nextToken()) != nullptr) {
        destAddressStr.push_back(token);
        L3Address result;
        L3AddressResolver().tryResolve(token, result);
        if (result.isUnspecified())
            EV_ERROR << "cannot resolve destination address: " << token << endl;
        destAddresses.push_back(result);
    }

    if (!destAddresses.empty()) {
        selfMsg->setKind(SEND);
        processSend();
    }
    else {
        if (stopTime >= SIMTIME_ZERO) {
            selfMsg->setKind(STOP);
            scheduleAt(stopTime, selfMsg);
        }
    }
}

void UdpFloodApp::processSend(){
    sendPacket();
    simtime_t d = simTime() + par("sendInterval");
    if (stopTime < SIMTIME_ZERO || d < stopTime) {
        selfMsg->setKind(SEND);
        scheduleAt(d, selfMsg);
    }
    else {
        selfMsg->setKind(STOP);
        scheduleAt(stopTime, selfMsg);
    }
}

void UdpFloodApp::handleMessageWhenUp(cMessage *msg){
    if (msg->isSelfMessage()) {
        ASSERT(msg == selfMsg);
        switch (selfMsg->getKind()) {
            case START:
                processStart();
                break;

            case SEND:
                processSend();
                break;

            case STOP:
                socket.close();
                break;

            default:
                throw cRuntimeError("Invalid kind %d in self message", (int)selfMsg->getKind());
        }
    }
    else
        socket.processMessage(msg);
}



void UdpFloodApp::refreshDisplay() const{
    ApplicationBase::refreshDisplay();

    char buf[100];
    sprintf(buf, "sent: %d pks", numSent);
    //getDisplayString().setTagArg("t", 0, buf);
}

L3Address UdpFloodApp::chooseDestAddr(){
    int k = intrand(destAddresses.size());
    if (destAddresses[k].isUnspecified() || destAddresses[k].isLinkLocal()) {
        L3AddressResolver().tryResolve(destAddressStr[k].c_str(), destAddresses[k]);
    }
    return destAddresses[k];
}

void UdpFloodApp::sendPacket(){
    std::ostringstream str;
    str << packetName << "-" << numSent;
    Packet *packet = new Packet(str.str().c_str());
    const auto& payload = makeShared<ApplicationPacket>();
    payload->setChunkLength(B(par("messageLength")));
    payload->setSequenceNumber(numSent);
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    packet->insertAtBack(payload);
    L3Address destAddr = chooseDestAddr();
    emit(packetSentSignal, packet);
    socket.sendTo(packet, destAddr, destPort);
    numSent++;
}

void UdpFloodApp::handleStartOperation(LifecycleOperation *operation){
    simtime_t start = std::max(startTime, simTime());
    if ((stopTime < SIMTIME_ZERO) || (start < stopTime) || (start == stopTime && startTime == stopTime)) {
        selfMsg->setKind(START);
        scheduleAt(start, selfMsg);
    }
}

void UdpFloodApp::handleStopOperation(LifecycleOperation *operation){
    cancelEvent(selfMsg);
    socket.close();
}

void UdpFloodApp::handleCrashOperation(LifecycleOperation *operation){
    cancelEvent(selfMsg);
    socket.destroy();
}

void UdpFloodApp::socketDataArrived(UdpSocket *socket, Packet *packet){
    delete packet;
}

void UdpFloodApp::socketErrorArrived(UdpSocket *socket, Indication *indication){
    EV_WARN << "Ignoring UDP error report " << indication->getName() << endl;
    delete indication;
}

void UdpFloodApp::socketClosed(UdpSocket *socket){
    if (operationalState == State::STOPPING_OPERATION)
        startActiveOperationExtraTimeOrFinish(par("stopOperationExtraTime"));
}

}//namespace inet





