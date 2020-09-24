/*
 * FilterRuleTable.h
 *
 *  Created on: 2020Äê9ÔÂ15ÈÕ
 *      Author: QianCheng
 */

#ifndef INET__EXTRA_NETWORKLAYER_FILTERRULETABLE_H_
#define INET__EXTRA_NETWORKLAYER_FILTERRULETABLE_H_

#include <vector>

#include "inet/common/INETDefs.h"
#include "inet/common/lifecycle/ILifecycle.h"
#include "inet/networklayer/contract/ipv4/Ipv4Address.h"
#include "inet/_extra/networklayer/FilterRule.h"
#include "inet/common/packet/packet.h"

namespace inet{

class INET_API FilterRuleTable : public cSimpleModule{
    enum FilterType{
        IDLE = 0,
        BLACK_LIST =1,
        WHITE_LIST =2
    };

  private:
    int numPreConfig;
    FilterType filterType;
    typedef std::vector<FilterRule *> FilterRules;
    FilterRules rules;


  protected:
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void addFilterRule(FilterRule * entry);
    virtual bool matchPacket(Packet * packet);


};

}



#endif /* INET__EXTRA_NETWORKLAYER_FILTERRULETABLE_H_ */
