/*
 * PacketGenerator.cc
 *
 *  Created on: 2020Äê8ÔÂ30ÈÕ
 *      Author: bjche
 */

#include "inet/_extra/transportlayer/PacketGenerator.h"
#include "inet/common/checksum/TcpIpChecksum.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/lifecycle/LifecycleOperation.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/networklayer/ipv4/Icmp.h"
#include "inet/networklayer/contract/IL3AddressType.h"
#include "inet/networklayer/common/L3Address.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/networklayer/common/L3AddressTag_m.h"
#include "inet/transportlayer/tcp_common/TcpHeader.h"
#include "inet/transportlayer/tcp/Tcp.h"
#include "inet/transportlayer/tcp/TcpConnection.h"
#include "inet/transportlayer/common/L4Tools.h"
#include "inet/transportlayer/common/CrcMode_m.h"
#include "inet/transportlayer/common/L4PortTag_m.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo.h"
#include "inet/transportlayer/udp/Udp.h"
#include "inet/transportlayer/udp/UdpHeader_m.h"
#include "inet/applications/common/SocketTag_m.h"
#include "inet/applications/base/ApplicationPacket_m.h"


#include <iostream>

namespace inet{
using namespace tcp;

Define_Module(PacketGenerator);

void PacketGenerator::initialize(int stage){
    OperationalBase::initialize(stage);
    if (stage == INITSTAGE_LOCAL) {
        localPort = par("localPort");
        destPort = par("destPort");
        startTime = par("startTime");
        stopTime = par("stopTime");
        packetName = par("packetName");
        selfMsg = new cMessage("sendTimer");
        numPacketType = getPacketType(par("packetType"));
    }
}

void PacketGenerator::handleMessageWhenUp(cMessage *msg){
    switch(numPacketType){
        case TCP_SYN:
        case TCP_SYNACK:
        case TCP_ACK:
        case TCP_RST:
            sendTcpPacket(numPacketType);
            break;
        case UDP:
            sendUdpPacket();
            break;
        case ICMP:
            sendIcmpPacket();
            break;
        default:
            throw cRuntimeError("Wrong PacketType! in handleMessageWhenUp");
    }

    simtime_t d = simTime() + par("sendInterval");
    if (stopTime < SIMTIME_ZERO || d < stopTime) {
        scheduleAt(d, selfMsg);
    }
    else {
        scheduleAt(stopTime, selfMsg);
    }
}

void PacketGenerator::sendTcpPacket(int numPacketType){
    ASSERT(destAddr.getType() == L3Address::IPv4);
    const auto& tcpseg = makeShared<TcpHeader>();
    Packet *packet = new Packet(packetName);

    localAddr = L3AddressResolver().resolve(par("localAddr"));
    destAddr = L3AddressResolver().resolve(par("destAddr"));
    IL3AddressType *addressType = destAddr.getAddressType();
    packet->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(addressType->getNetworkProtocol());
    auto addresses = packet->addTagIfAbsent<L3AddressReq>();
    addresses->setSrcAddress(localAddr);
    addresses->setDestAddress(destAddr);
    switch(numPacketType){
        case TCP_SYN:
            tcpseg->setSynBit(true);
            break;
        case TCP_SYNACK:
            tcpseg->setSynBit(true);
            tcpseg->setAckBit(true);
            break;
        case TCP_ACK:
            tcpseg->setAckBit(true);
            break;
        case TCP_RST:
            tcpseg->setRstBit(true);
            break;
        default:
            throw cRuntimeError("Wrong TCP PacketType!");
    }
    tcpseg->setSrcPort(localPort);
    tcpseg->setDestPort(destPort);
    auto pseudoHeader = makeShared<TransportPseudoHeader>();
    pseudoHeader->setSrcAddress(localAddr);
    pseudoHeader->setDestAddress(destAddr);
    pseudoHeader->setNetworkProtocolId(Protocol::ipv4.getId());
    pseudoHeader->setProtocolId(6);
    pseudoHeader->setPacketLength(tcpseg->getChunkLength());
    // pseudoHeader length: ipv4: 12 bytes, ipv6: 40 bytes, other: ???
    pseudoHeader->setChunkLength(B(12));
    MemoryOutputStream stream;
    Chunk::serialize(stream, pseudoHeader);
    uint16_t crc = TcpIpChecksum::checksum(stream.getData());
    tcpseg->setCrc(crc);
    tcpseg->setCrcMode(CRC_COMPUTED);
    insertTransportProtocolHeader(packet, Protocol::tcp, tcpseg);

    take(packet);
    send(packet, "ipOut");
    numSent++;
}

void PacketGenerator::sendUdpPacket(){
    int socketId = getSimulation()->getUniqueNumber();
    ASSERT(destAddr.getType() == L3Address::IPv4);
    Packet *packet = new Packet(packetName);
    const auto& payload = makeShared<ApplicationPacket>();

    payload->setChunkLength(B(1472));
    payload->setSequenceNumber(numSent++);
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    payload->addTagIfAbsent<SocketInd>()->setSocketId(socketId);
    packet->insertAtBack(payload);

    destAddr = L3AddressResolver().resolve(par("destAddr"));
    auto addressReq = packet->addTagIfAbsent<L3AddressReq>();
    addressReq->setDestAddress(destAddr);
    if (destPort != -1)
        packet->addTagIfAbsent<L4PortReq>()->setDestPort(destPort);
    auto& tags = getTags(packet);
    tags.addTagIfAbsent<SocketReq>()->setSocketId(socketId);
    packet->addTagIfAbsent<DispatchProtocolReq>()->setProtocol(&Protocol::ipv4);

    auto udpHeader = makeShared<UdpHeader>();
    udpHeader->setSourcePort(localPort);
    udpHeader->setDestinationPort(destPort);
    udpHeader->setCrcMode(CRC_COMPUTED);

    auto udpData = packet->peekData(Chunk::PF_ALLOW_EMPTY);
    auto crc = Udp::computeCrc(&Protocol::ipv4, localAddr, destAddr, udpHeader, udpData);
    udpHeader->setCrc(crc);

    insertTransportProtocolHeader(packet, Protocol::udp, udpHeader);
    packet->setKind(0);
    send(packet, "ipOut");
}

void PacketGenerator::sendIcmpPacket(){
    ASSERT(destAddr.getType() == L3Address::IPv4);
    Packet *packet = new Packet(packetName);
    localAddr = L3AddressResolver().resolve(par("localAddr"));
    destAddr = L3AddressResolver().resolve(par("destAddr"));
    auto payload = makeShared<ByteCountChunk>(B(1472));//Max length of payload
    const auto& request = makeShared<IcmpEchoRequest>();

    request->setIdentifier(getSimulation()->getUniqueNumber());
    request->setSeqNumber(numSent++);
    packet->insertAtBack(payload);
    Icmp::insertCrc(CRC_COMPUTED, request, packet);
    packet->insertAtFront(request);
    packet->addTag<PacketProtocolTag>()->setProtocol(&Protocol::icmpv4);

    auto addressReq = packet->addTag<L3AddressReq>();
    addressReq->setSrcAddress(localAddr);
    addressReq->setDestAddress(destAddr);
    auto& tags = getTags(packet);
    tags.addTagIfAbsent<DispatchProtocolReq>()->setProtocol(&Protocol::ipv4);
    //tags.addTagIfAbsent<SocketReq>()->setSocketId(socketId);
    send(packet, "ipOut");
}

void PacketGenerator::finish(){
    recordScalar("packets sent", numSent);
}

void PacketGenerator::handleStartOperation(LifecycleOperation *operation){
    simtime_t start = std::max(startTime, simTime());
    if ((stopTime < SIMTIME_ZERO) || (start < stopTime) || (start == stopTime && startTime == stopTime)) {
        scheduleAt(start, selfMsg);
    }
}

int PacketGenerator::getPacketType(const char* packetType){
    if(strcmp("TCP_SYN",packetType) == 0)
        return TCP_SYN;
    else if(strcmp("TCP_SYNACK",packetType) == 0){
        return TCP_SYNACK;
    }
    else if(strcmp("TCP_ACK",packetType) == 0){
        return TCP_ACK;
    }
    else if(strcmp("TCP_RST",packetType) == 0){
        return TCP_RST;
    }
    else if(strcmp("UDP",packetType) == 0){
        return UDP;
    }
    else if(strcmp("ICMP",packetType) == 0){
        return ICMP;
    }
    else{
        throw cRuntimeError("PacketGenerator: Wrong PacketType");
    }
}

}//namespace inet




