/*
 * TestSocketApp.h
 *
 *  Created on: 2020Äê9ÔÂ18ÈÕ
 *      Author: QianCheng
 */

#ifndef INET__EXTRA_APPLICATIONS_TESTSOCKETAPP_TESTSOCKETAPP_H_
#define INET__EXTRA_APPLICATIONS_TESTSOCKETAPP_TESTSOCKETAPP_H_

#include "inet/common/INETDefs.h"
#include "inet/common/socket/SocketMap.h"
#include "inet/common/lifecycle/ILifecycle.h"
#include "inet/common/lifecycle/LifecycleOperation.h"
#include "inet/common/lifecycle/NodeStatus.h"
#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/tcp/TcpSocket.h"
#include "inet/applications/tcpapp/TcpAppBase.h"
#include "inet/applications/tcpapp/TcpServerHostApp.h"

namespace inet {

class INET_API TcpSocketServer : public TcpServerHostApp {
  protected:
    long bytesRcvd = 0;

  protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void finish() override;
    virtual void refreshDisplay() const override;

    friend class TcpSocketServerThread;
};

class INET_API TcpSocketServerThread : public TcpServerThreadBase {
  protected:
    long bytesRcvd;
    TcpSocketServer *socketServerModule = nullptr;

    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void refreshDisplay() const override;

    virtual void established() override;
    virtual void dataArrived(Packet *msg, bool urgent) override;
    virtual void timerExpired(cMessage *timer) override { throw cRuntimeError("Model error: unknown timer message arrived"); }
    virtual void init(TcpServerHostApp *hostmodule, TcpSocket *socket) override { TcpServerThreadBase::init(hostmodule, socket); socketServerModule = check_and_cast<TcpSocketServer *>(hostmod); }

};

class INET_API TcpSocketClient : public TcpAppBase {
  protected:
    cMessage *timeoutMsg = nullptr;
    bool earlySend = false;    // if true, don't wait with sendRequest() until established()
    int numRequestsToSend = 0;    // requests to send in this session
    simtime_t startTime;
    simtime_t stopTime;

    virtual void sendRequest();
    virtual void rescheduleOrDeleteTimer(simtime_t d, short int msgKind);

    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleTimer(cMessage *msg) override;

    virtual void socketEstablished(TcpSocket *socket) override;
    virtual void socketDataArrived(TcpSocket *socket, Packet *msg, bool urgent) override;
    virtual void socketClosed(TcpSocket *socket) override;
    virtual void socketFailure(TcpSocket *socket, int code) override;

    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override;
    virtual void handleCrashOperation(LifecycleOperation *operation) override;

    virtual void close() override;
};

}//namespace inet



#endif /* INET__EXTRA_APPLICATIONS_TESTSOCKETAPP_TESTSOCKETAPP_H_ */
