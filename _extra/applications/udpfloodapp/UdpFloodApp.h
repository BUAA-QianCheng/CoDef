/*
 * MyApp.h
 *
 *  Created on: 2020Äê8ÔÂ27ÈÕ
 *      Author: bjche
 */

#ifndef INET_APPLICATIONS_EXTRAAPPS_UDPFLOODAPP_H_
#define INET_APPLICATIONS_EXTRAAPPS_UDPFLOODAPP_H_

#include <omnetpp.h>

#include "inet/common/INETDefs.h"
#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"

namespace inet {

class INET_API UdpFloodApp : public ApplicationBase, public UdpSocket::ICallback {
  protected:
    enum SelfMsgKinds { START = 1, SEND, STOP };
    //parameters
    std::vector<L3Address> destAddresses;
    std::vector<std::string> destAddressStr;
    int localPort = -1;
    int destPort = -1;
    simtime_t startTime;
    simtime_t stopTime;
    const char *packetName = nullptr;

    //state
    UdpSocket socket;
    cMessage *selfMsg = nullptr;
    //SocketMap socketMap;

    //statistics
    long numSent = 0;

  protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessageWhenUp(cMessage *msg) override;
    virtual void finish() override;
    virtual void refreshDisplay() const override;

    virtual L3Address chooseDestAddr();
    virtual void sendPacket();
    virtual void processStart();
    virtual void processSend();

    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override;
    virtual void handleCrashOperation(LifecycleOperation *operation) override;

    virtual void socketDataArrived(UdpSocket *socket, Packet *packet) override;
    virtual void socketErrorArrived(UdpSocket *socket, Indication *indication) override;
    virtual void socketClosed(UdpSocket *socket) override;

  public:
    UdpFloodApp();
    virtual ~UdpFloodApp();
};

}


#endif /* INET_APPLICATIONS_EXTRAAPPS_UDPFLOOD_MYAPP_H_ */
