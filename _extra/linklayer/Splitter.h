/*
 * Splitter.h
 *
 *  Created on: 2020Äê9ÔÂ2ÈÕ
 *      Author: bjche
 */

#ifndef INET__EXTRA_LINKLAYER_SPLITTER_H_
#define INET__EXTRA_LINKLAYER_SPLITTER_H_

#include <omnetpp.h>
#include "inet/common/INETDefs.h"

using namespace omnetpp;

namespace inet {
class Splitter : public cSimpleModule {
  protected:
    int numPorts;
    int inputGateBaseId;
    int outputGateBaseId;
    short testKind;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};
}//namespace inets

#endif /* INET__EXTRA_LINKLAYER_SPLITTER_H_ */
