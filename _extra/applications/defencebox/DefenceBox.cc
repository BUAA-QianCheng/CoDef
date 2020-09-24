/*
 * DefenceBox.cc
 *
 *  Created on: 2020Äê9ÔÂ14ÈÕ
 *      Author: QianCheng
 */

#include "inet/_extra/applications/defencebox/DefenceBox.h"

namespace inet {

Define_Module(DefenceBox);

void DefenceBox::initialize(){
    if((gateSize("ethgin") != gateSize("ethgout")) || (gateSize("pppgin") != gateSize("pppgout"))){
        throw cRuntimeError("DefenceBox : Wrong Gate Number of Ethg or Pppg!");
    }
    ethPorts = gateSize("ethgin");
    pppPorts = gateSize("pppgin");
    ethInBaseId = gateBaseId("ethgin$i");
    ethOutBaseId = gateBaseId("ethgout$o");
    pppInBaseId = gateBaseId("pppgin$i");
    pppOutBaseId = gateBaseId("pppgout$o");

    for(int i = 0 ; i < ethPorts; i++)
        gate(ethInBaseId + i)->setDeliverOnReceptionStart(true);
    for(int j = 0 ; j < pppPorts; j++)
        gate(pppInBaseId + j)->setDeliverOnReceptionStart(true);
}

void DefenceBox::handleMessage(cMessage *msg){
    //If not message from agents deliver msg
    int arrivalPort = msg->getArrivalGate()->getId();
    if(arrivalPort >= ethInBaseId && arrivalPort <= ethInBaseId + ethPorts){
        cGate *ogate = gate(arrivalPort - ethInBaseId + ethOutBaseId);
        ogate->getTransmissionChannel()->forceTransmissionFinishTime(SIMTIME_ZERO);
        send(msg, ogate);
    }
    else if(arrivalPort >= pppInBaseId && arrivalPort <= pppInBaseId + pppPorts){
        cGate *ogate = gate(arrivalPort - pppInBaseId + pppOutBaseId);
        ogate->getTransmissionChannel()->forceTransmissionFinishTime(SIMTIME_ZERO);
        send(msg, ogate);
    }
    else if(arrivalPort >= ethOutBaseId && arrivalPort <= ethOutBaseId + ethPorts){
        cGate *ogate = gate(arrivalPort - ethOutBaseId + ethInBaseId);
        ogate->getTransmissionChannel()->forceTransmissionFinishTime(SIMTIME_ZERO);
        send(msg, ogate);
    }
    else if(arrivalPort >= pppOutBaseId && arrivalPort <= pppOutBaseId + ethPorts){
        cGate *ogate = gate(arrivalPort - pppOutBaseId + pppInBaseId);
        ogate->getTransmissionChannel()->forceTransmissionFinishTime(SIMTIME_ZERO);
        send(msg, ogate);
    }
    else{
        throw cRuntimeError("DefenceBox : Wrong Msg Gate Number %d", arrivalPort);
    }
}

}// namespcae inet

