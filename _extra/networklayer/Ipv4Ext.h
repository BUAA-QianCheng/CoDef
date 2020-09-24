/*
 * Ipv4Ext.h
 *
 *  Created on: 2020Äê9ÔÂ15ÈÕ
 *      Author: QianCheng
 */

#ifndef INET__EXTRA_NETWORKLAYER_IPV4EXT_H_
#define INET__EXTRA_NETWORKLAYER_IPV4EXT_H_

#include "inet/networklayer/ipv4/Ipv4.h"
#include "inet/common/packet/Packet.h"
#include "inet/_extra/networklayer/FilterRuleTable.h"

namespace inet{

class INET_API Ipv4Ext : public Ipv4{
  protected:
    FilterRuleTable *frt = nullptr;
  protected:
    virtual void initialize(int stage) override;
    virtual void handleIncomingDatagram(Packet *packet) override;
};

} //namespace inet


#endif /* INET__EXTRA_NETWORKLAYER_IPV4EXT_H_ */
