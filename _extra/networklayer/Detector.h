/*
 * Detector.h
 *
 *  Created on: 2020Äê9ÔÂ2ÈÕ
 *      Author: bjche
 */

#ifndef INET__EXTRA_NETWORKLAYER_DETECTOR_H_
#define INET__EXTRA_NETWORKLAYER_DETECTOR_H_

#include <omnetpp.h>

namespace inet {

using namespace omnetpp;

class Detector : public cSimpleModule {
  protected:

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

}//namespace inet



#endif /* INET__EXTRA_NETWORKLAYER_DETECTOR_H_ */
