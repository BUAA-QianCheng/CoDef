/*
 * PacketMatchExpression.h
 *
 *  Created on: 2020Äê9ÔÂ6ÈÕ
 *      Author: bjche
 */

#ifndef INET__EXTRA_COMMON_PACKET_PACKETMATCHEXPRESSION_H_
#define INET__EXTRA_COMMON_PACKET_PACKETMATCHEXPRESSION_H_

#include <omnetpp.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include "inet/common/INETDefs.h"
#include "inet/common/packet/Packet.h"
#include "inet/_extra/transportlayer/PortRange_m.h"

namespace inet{

using namespace std;

enum Action{
    MATCH = 0,
    ACCEPT = 1,
    DROP = 2,
    RATE_LIMIT = 3
};

class PacketMatchExpression {
  protected:
    const char* expression = "";
    const char* ruleName = "";
    double rateLimit;
    Action action;
    vector<Ipv4Address> srcIpv4AddrList, destIpv4AddrList;
    vector<Ipv6Address> srcIpv6AddrList, destIpv6AddrList;
    vector<PortRange> srcPortList, destPortList;
    vector<string> l3ConditionList, l4ConditionList;

  public:
    virtual bool isMark(char c);
    virtual PortRange readPortRange(string s);
    virtual void readAction(string s);
    virtual void parseExpression();
    virtual void setExpression(string exp);
    virtual string getExpression(){ return string(expression); };

    //virtual string generateExpression(Packet packet);
    //virtual bool checkGrammar(const char* expression);
    virtual bool matchExpression(const char* pktExp);
};

}//namespace inet



#endif /* INET__EXTRA_COMMON_PACKET_PACKETMATCHEXPRESSION_H_ */

