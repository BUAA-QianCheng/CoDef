/*
 * DefenceBox.h
 *
 *  Created on: 2020Äê9ÔÂ14ÈÕ
 *      Author: QianCheng
 */

#ifndef INET__EXTRA_APPLICATIONS_DEFENCEBOX_DEFENCEBOX_H_
#define INET__EXTRA_APPLICATIONS_DEFENCEBOX_DEFENCEBOX_H_

#include <omnetpp.h>
#include "inet/common/INETDefs.h"

namespace inet{

class DefenceBox : public cSimpleModule{
  protected:
    int ethPorts;
    int pppPorts;
    int ethInBaseId;
    int ethOutBaseId;
    int pppInBaseId;
    int pppOutBaseId;
    bool triggerMitigation;
    bool triggerFilterRules;
    bool triggerBypass;

  protected:
     virtual void initialize() override;
     virtual void handleMessage(cMessage *msg) override;
};

} //namespace inet

#endif /* INET__EXTRA_APPLICATIONS_DEFENCEBOX_DEFENCEBOX_H_ */
