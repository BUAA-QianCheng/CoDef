/*
 * PacketGenerator.h
 *
 *  Created on: 2020Äê8ÔÂ30ÈÕ
 *      Author: bjche
 */

#ifndef INET__EXTRA_TRANSPORTLAYER_PACKETGENERATOR_H_
#define INET__EXTRA_TRANSPORTLAYER_PACKETGENERATOR_H_

#include <omnetpp.h>

#include "inet/common/INETDefs.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/L3Address.h"
#include "inet/transportlayer/base/TransportProtocolBase.h"
#include "inet/transportlayer/tcp/TcpConnection.h"

namespace inet{

enum PacketType{TCP_SYN =1, TCP_SYNACK, TCP_ACK, TCP_RST, UDP, ICMP};

class INET_API PacketGenerator : public TransportProtocolBase {
  public:
    L3Address localAddr;
    L3Address destAddr;
    int localPort;
    int destPort;
    const char *packetName = nullptr;
    int numPacketType;
    simtime_t startTime;
    simtime_t stopTime;
    cMessage *selfMsg = nullptr;

    long numSent = 0;

  protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; };
    virtual void finish() override;
    virtual void refreshDisplay() const override{ OperationalBase::refreshDisplay();};

    virtual void handleMessageWhenUp(cMessage* msg) override;

    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override{ cancelEvent(selfMsg); };
    virtual void handleCrashOperation(LifecycleOperation *operation) override{ cancelEvent(selfMsg); };

    virtual int getPacketType(const char* packetType);
    virtual void sendTcpPacket(int numPacketType);
    virtual void sendUdpPacket();
    virtual void sendIcmpPacket();

};

} //namespace inet


#endif /* INET__EXTRA_TRANSPORTLAYER_PACKETGENERATOR_H_ */
