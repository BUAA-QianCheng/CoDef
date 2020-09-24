/*
 * CoDefClient.h
 *
 *  Created on: 2020Äê8ÔÂ31ÈÕ
 *      Author: bjche
 */

#ifndef INET__EXTRA_APPLICATIONS_CODEFAGENT_CODEFCLIENT_H_
#define INET__EXTRA_APPLICATIONS_CODEFAGENT_CODEFCLIENT_H_

#include <omnetpp.h>

#include "inet/common/INETDefs.h"
#include "inet/applications/tcpapp/TcpAppBase.h"
#include "inet/common/lifecycle/LifecycleOperation.h"
#include "inet/common/lifecycle/NodeStatus.h"
#include "inet/_extra/applications/codefagent/CoDefMsgs_m.h"
#include "inet/_extra/applications/codefagent/CoDefMitigation_m.h"

namespace inet{

using namespace std;

class INET_API CoDefClient : public TcpAppBase{
  const int CODEF_PORT_NUM = 4646; //refer to DOTS suggested port num 4646

  protected:
    enum msgKind{MSGKIND_CONNECT=1, MSGKIND_ON, MSGKIND_CLOSE};
    //parameters
    cMessage *timeoutMsg = nullptr;

    simtime_t tOpen;
    simtime_t tSend;
    simtime_t tClose;
    //state


    //Target State
        //target list[]
        //

    //Client State
    string cuid = "";
    bool registered  = false;
    bool peerHbStatus = false;


    //Seession State

    //Server State
        //ServerAddress
        //


    //
  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void finish() override;
    virtual void refreshDisplay() const override;

    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override;
    virtual void handleCrashOperation(LifecycleOperation *operation) override;

    virtual void handleTimer(cMessage *msg) override;
    virtual void socketEstablished(TcpSocket *socket) override;
    virtual void socketDataArrived(TcpSocket *socket, Packet *msg, bool urgent) override;
    virtual void socketClosed(TcpSocket *socket) override;
    virtual void socketFailure(TcpSocket *socket, int code) override;

  protected:
    virtual void generateCuid();
    virtual void processPacket();

    virtual void regist();
    virtual void unregist();

    virtual void sendHeartBeat();
    virtual void sendMitigationRequest(RequestType reqType, int mid);
    virtual void sendMitigationRequest(RequestType reqType, int mid, bool attackStatus);
    virtual void sendMitigationRequest(Request reqType, int mid, MitigationTarget *target , int lifetime, bool triggerMitigation);

    virtual void sendFilterRuleRequest(string fliterRule);
    //virtual void sendAliasRequest();
};

}



#endif /* INET__EXTRA_APPLICATIONS_CODEFAGENT_CODEFCLIENT_H_ */
