/*
 * Detector.cc
 *
 *  Created on: 2020Äê9ÔÂ2ÈÕ
 *      Author: bjche
 */

#include "inet/_extra/networklayer/Detector.h"
#include "inet/common/packet/Packet.h"
#include "inet/common/packet/PacketFilter.h"
#include "inet/linklayer/ethernet/EtherPhyFrame_m.h"

namespace inet{

Define_Module(Detector);

void Detector::initialize(){

}

void Detector::handleMessage(cMessage *msg){
    EthernetSignal * signal = check_and_cast<EthernetSignal *>(msg);
    auto packet = check_and_cast<Packet *>(signal->decapsulate());
    delete msg;
    if(strstr(packet->getName(), "Flood") != nullptr){
        std::string banner = packet->getName();
        this->bubble(banner.c_str());
    }
    delete packet;
}

}

