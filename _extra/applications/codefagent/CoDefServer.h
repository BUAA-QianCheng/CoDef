/*
 * CoDefServer.h
 *
 *  Created on: 2020Äê8ÔÂ31ÈÕ
 *      Author: bjche
 */

#ifndef INET__EXTRA_APPLICATIONS_CODEFAGENT_CODEFSERVER_H_
#define INET__EXTRA_APPLICATIONS_CODEFAGENT_CODEFSERVER_H_

#include "inet/applications/tcpapp/TcpServerHostApp.h"

namespace inet{

class INET_API CoDefServer : public TcpServerHostApp{
  protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void finish() override;
    virtual void refreshDisplay() const override;


  public:
    CoDefServer();
    ~CoDefServer();

    friend class CoDefServerThread;
};

class INET_API CoDefServerThread : public TcpServerThreadBase{
  protected:
    CoDefServer *coDefServerModule = nullptr;

    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void refreshDisplay() const override;

    virtual void established() override;
    virtual void dataArrived(Packet *msg, bool urgent) override;
    virtual void timerExpired(cMessage *timer) override { throw cRuntimeError("Model error: unknown timer message arrived"); }
    virtual void init(TcpServerHostApp *hostmodule, TcpSocket *socket) override { TcpServerThreadBase::init(hostmodule, socket); sinkAppModule = check_and_cast<TcpSinkApp *>(hostmod); }
};

}



#endif /* INET__EXTRA_APPLICATIONS_CODEFAGENT_CODEFSERVER_H_ */
