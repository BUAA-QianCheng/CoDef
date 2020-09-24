/*
 * FilterRule.h
 *
 *  Created on: 2020Äê9ÔÂ16ÈÕ
 *      Author: QianCheng
 */

/* see inet/networklayer/common/IpProtocolId.msg
enum IpProtocolId {
    IP_PROT_ICMP = 1,
    IP_PROT_IGMP = 2,
    IP_PROT_IP = 4,
    IP_PROT_TCP = 6,
    IP_PROT_EGP = 8,
    IP_PROT_IGP = 9,
    IP_PROT_UDP = 17,
    IP_PROT_XTP = 36,
    IP_PROT_IPv6 = 41,
    IP_PROT_RSVP = 46,
    IP_PROT_IPv6_ICMP = 58,
    IP_PROT_NONE = 59,
    IP_PROT_EIGRP = 88,
    IP_PROT_OSPF = 89,
    IP_PROT_OSPFv3 = 90,
    IP_PROT_PIM = 103,
    IP_PROT_VRRP = 112,
    IP_PROT_SCTP = 132,
    IP_PROT_DSR = 48,
    IP_PROT_MANET = 138,
    IP_PROT_IPv6EXT_HOP = 0,
    IP_PROT_IPv6EXT_DEST = 60,
    IP_PROT_IPv6EXT_ROUTING = 43,
    IP_PROT_IPv6EXT_FRAGMENT = 44,
    IP_PROT_IPv6EXT_AUTH = 51,
    IP_PROT_IPv6EXT_ESP = 50,
    IP_PROT_IPv6EXT_MOB = 135,
    IP_PROT_FLOODING = 250,
    IP_PROT_PROBABILISTIC = 251,
    IP_PROT_WISE = 252,
    IP_PROT_NEXT_HOP_FORWARDING = 253,
    IP_PROT_ECHO = 254
};*/

#ifndef INET__EXTRA_NETWORKLAYER_FILTERRULE_H_
#define INET__EXTRA_NETWORKLAYER_FILTERRULE_H_

#include <omnetpp.h>

#include "inet/common/INETDefs.h"

#include "inet/networklayer/ipv4/Ipv4Header_m.h"
#include "inet/_extra/networklayer/FilterRule_m.h"
#include "inet/_extra/networklayer/FilterRuleTable.h"
#include "inet/common/packet/Packet.h"
#include "inet/transportlayer/tcp_common/TcpHeader.h"
#include "inet/networklayer/common/L3Address.h"



namespace inet {

using namespace tcp;

enum L3Type {
    UNSPEC = 0,
    IPV4 = 1,
    IPV6 = 2
};

enum L4Type {
    UNSET = 0,
    TCP = 1,
    UDP = 2,
    ICMP =3
};

class INET_API FilterRule : public cObject{
  private:
    FilterRuleTable * frt;
    L3Type l3 = UNSPEC;
    L4Type l4 = UNSET;
    Matches matches;
    Action action;

  public:
    virtual std::string ipv4MatchStr(Ipv4Match m) const;
    virtual std::string ipv6MatchStr(Ipv6Match m) const;
    virtual std::string portRangeStr(PortRange pr) const;
    virtual std::string tcpMatchStr(TcpMatch tm) const;
    virtual std::string udpMatchStr(UdpMatch um) const;
    virtual std::string icmpMatchStr(IcmpMatch im) const;

    virtual std::string str() const override;
    virtual std::string detailedInfo() const OMNETPP5_CODE(override);
  public:
    virtual void setFilterRuleTable(FilterRuleTable * frt){ this->frt = frt; }
    FilterRuleTable *getFilterRuleTable() const { return frt; }

    virtual void setL3Type(L3Type l3){ this->l3 = l3; }
    virtual L3Type getL3Type(){ return this->l3; }

    virtual void setL4Type(L4Type l4) { this->l4 = l4; }
    virtual L4Type getL4Type() { return this->l4; }

    virtual void readAction(std::string s);
    virtual void readL3(std::string s);
    virtual void readL4(std::string s);
    virtual uint8_t readOp(std::string s);

    virtual void readPortRange(std::string s, PortRange *pr);
    virtual void readFilterRule(std::string s);

    virtual bool matchIpv4Packet(Packet *packet) const;
    virtual bool matchIpv6Packet(Packet *packet) const;
    virtual bool matchTcpPacket(Packet *packet) const;
    virtual bool matchUdpPacket(Packet *packet) const;
    virtual bool matchIcmpPacket(Packet *packet) const;

    virtual bool isPortRangeUnspecified(PortRange pr) const;
    virtual bool inPortRange(uint16_t portNum, PortRange pr) const;
    virtual uint16_t getTcpFlags(Ptr<const TcpHeader> h) const;
};

} //namespace inet



#endif /* INET__EXTRA_NETWORKLAYER_FILTERRULE_H_ */
