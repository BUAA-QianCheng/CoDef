/*
 * Splitter.cc
 *
 *  Created on: 2020Äê9ÔÂ2ÈÕ
 *      Author: bjche
 */

#include "inet/_extra/linklayer/Splitter.h"

namespace inet {

Define_Module(Splitter);

void Splitter::initialize(){
    numPorts = gateSize("ethg");
    inputGateBaseId = gateBaseId("ethg$i");
    outputGateBaseId = gateBaseId("ethg$o");
    testKind = 0;
    for (int i = 0; i < numPorts; i++)
        gate(inputGateBaseId + i)->setDeliverOnReceptionStart(true);
}

void Splitter::handleMessage(cMessage *msg){
    int arrivalPort = msg->getArrivalGate()->getIndex();
    if (numPorts <= 1) {
        delete msg;
        return;
    }
    for (int i = 0; i < numPorts; i++) {
        if (i != arrivalPort) {
            cGate *ogate = gate(outputGateBaseId + i);
            if (!ogate->isConnected())
                continue;
            bool isLast = (arrivalPort == numPorts - 1) ? (i == numPorts - 2) : (i == numPorts - 1);
            cMessage *msg2 = isLast ? msg : msg->dup();
            ogate->getTransmissionChannel()->forceTransmissionFinishTime(SIMTIME_ZERO);
            msg2->setKind(testKind++);
            send(msg2, ogate);
            if (isLast)
                msg = nullptr;
            }
        }
        delete msg;
}

}//namespace inet
