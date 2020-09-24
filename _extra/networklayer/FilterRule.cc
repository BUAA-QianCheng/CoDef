/*
 * FilterRule.cc
 *
 *  Created on: 2020Äê9ÔÂ16ÈÕ
 *      Author: QianCheng
 */

#include "inet/_extra/networklayer/FilterRule.h"

#include "inet/networklayer/ipv4/Ipv4Header_m.h"
#include "inet/networklayer/contract/ipv4/Ipv4Address.h"
#include "inet/networklayer/ipv6/Ipv6Header.h"
#include "inet/networklayer/contract/ipv6/Ipv6Address.h"
#include "inet/transportlayer/udp/UdpHeader_m.h"
#include "inet/networklayer/ipv4/IcmpHeader_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"

#include <stdio.h>

namespace inet{

using namespace tcp;

Register_Class(FilterRule);

void FilterRule::readAction(std::string str){
    const char * s = str.c_str();
    if(strncmp(s,"ACCEPT", 6) == 0){
        this->action.setForwarding(ACCEPT);
    }
    else if(strncmp(s,"DROP", 4) == 0){
        this->action.setForwarding(DROP);
    }
    else if(strncmp(s,"MATCH", 5) == 0){
        this->action.setForwarding(MATCH);
    }
    else if(strncmp(s, "RATE_LIMIT", 10)){
        this->action.setForwarding(RATE_LIMIT);
        double rateLimit = 0.0;
        for(int i = 10, dot = 0; i<strlen(s) ;i++){
            if(s[i] == ' ')
                continue;
            else if(s[i] >= '0' && s[0] <= '9'){
                if(dot == 0)
                    rateLimit = rateLimit*10.0 + (s[i]-'0');
                else
                    rateLimit = rateLimit + pow(0.1, dot++)*(s[i]-'0');
            }
            else if(s[i] == '.')
                dot = 1;
            else
                EV_ERROR << "readFilterRule(): Error in RATE_LIMIT! Check your Rule!" << endl;
            return ;
        }
    }
    else{
        EV_ERROR << "readFilterRule(): Wrong ACTION! Check your Rule!" << endl;
        return ;
    }
}

void FilterRule::readL3(std::string s){
    int mark=0, length=0, protocol=0, op=0, frag=0;
    L3Address srcAddr, destAddr;
    std::string srcAddrStr, destAddrStr, content;//content stands for contents in ()
    Ipv4Match ipv4Match;
    Ipv6Match ipv6Match;

    //start with srcAddr
    if(s.find('>') == s.npos){
        EV_ERROR << "readL3(): Lack '>'! Check your rule!";
        return ;
    }
    srcAddrStr = std::string(s, mark, s.find('>'));
    if(srcAddrStr.length() == 1 && srcAddrStr[0] == '*'){
        //ANY srcAddr
    }
    else{
        L3AddressResolver().tryResolve(srcAddrStr.c_str() ,srcAddr);
        this->l3 = (srcAddr.getType() == 1 ? IPV4 : IPV6);
    }
    mark = s.find('>');
    //then destAddr
    //locate end of addr
    if(s.find('(') == s.npos){
        //no Condition
        destAddrStr = std::string(s, mark+1, s.length() -1);
    }
    else{
        destAddrStr = std::string(s, mark+1, s.find('(', mark+1) - mark - 1);
    }
    //parse Addr
    if(destAddrStr.length() == 1 && srcAddrStr[0] == '*'){
        //ANY destAddr
    }
    else{
        L3AddressResolver().tryResolve(destAddrStr.c_str() ,destAddr);
        this->l3 = (srcAddr.getType() == 1 ? IPV4 : IPV6);
    }
    mark = s.find('(');
    //condition at last;
    if(mark != s.npos){
        content = std::string(s, mark+1, s.find(')', mark+1) - mark - 1);
        while(content.find(',', mark+1) != content.npos){
            std::string tmp = std::string(s, mark+1, s.find(',', mark+1) - mark - 1);
            if(strncmp(tmp.c_str(), "Length", 6) == 0){

                for(int i = 7; i<tmp.length(); i++){
                   if(tmp[i] >= '0' && tmp[i] <= '9')
                       length += length*10 + (tmp[i]-'0');
                   else{
                       EV_ERROR <<"readL3(): Wrong L3 Condition Length! Check your Rule!";
                       return ;
                   }
                }
            }
            else if(strncmp(tmp.c_str(), "Protocol", 8) == 0){
                for(int i = 9; i<tmp.length(); i++){
                    if(tmp[i] >= '0' && tmp[i] <= '9')
                        protocol += protocol*10 + (tmp[i]-'0');
                    else{
                        EV_ERROR <<"readL3(): Wrong L3 Condition Length! Check your Rule!";
                        return ;
                    }
                }
            }
            else if((op = readOp(tmp))!= -1){
                int j=0;
                switch(op){
                case 1:
                    j=3;//NOT
                    break;
                case 2:
                    j=5;//MATCH
                    break;
                case 9:
                    j=6;//NOTANY
                    break;
                case 10:
                    j=8;//NOTMATCH
                    break;
                default:
                    j=tmp.length();//last letter
                    EV_ERROR <<"readL3(): Wrong L3 Condition Op! Check your Rule!";
                    return ;
                }
                for(j; j<tmp.length(); j++){
                    if(tmp[j] >= '0' && tmp[j] <= '9')
                        frag += frag*10 + (tmp[j]-'0');
                    else{
                        EV_ERROR <<"readL3(): Wrong L3 Condition fragment! Check your Rule";
                        return ;
                    }
                }
            }
            else{
                EV_ERROR <<"readL3(): Wrong L3 Condition Op! Check your Rule!";
                return ;
            }
            mark = content.find(',', mark+1);
        }
    }
    if(this->l3 == IPV6){
        if(!srcAddr.isUnspecified())
            ipv6Match.setSrcNetwork(srcAddr.toIpv6());
        if(!destAddr.isUnspecified())
            ipv6Match.setDestNetwork(destAddr.toIpv6());
        if(length != 0)
            ipv6Match.setLength(length);
        if(protocol != 0)
            ipv6Match.setProtocol(protocol);
        if(op != 0){
            ipv6Match.setFragmentOp(op);
            ipv6Match.setFragmentType(frag);
        }
        this->matches.setIpv6(ipv6Match);
    }
    else{
        if(!srcAddr.isUnspecified())
            ipv4Match.setSrcNetwork(srcAddr.toIpv4());
        if(!destAddr.isUnspecified())
            ipv4Match.setDestNetwork(destAddr.toIpv4());
        if(length != 0)
            ipv4Match.setLength(length);
        if(protocol != 0)
            ipv4Match.setProtocol(protocol);
        if(op != 0){
            ipv4Match.setFragmentOp(op);
            ipv4Match.setFragmentType(frag);
        }
        this->matches.setIpv4(ipv4Match);
    }
}

void FilterRule::readL4(std::string s){
    //start with srcPort
    int mark=0, length=0, bitmask=0, op=0, type=-1, code = -1;
    std::string content;
    TcpMatch tcpMatch;
    UdpMatch udpMatch;
    IcmpMatch icmpMatch;
    PortRange srcPortRange, destPortRange;

    if(s[0] == '*'){
        //ANY srcPort
        mark = s.find('>');
    }
    else if(s[0] == '('){
        this->l4 = ICMP;
        content = std::string(s, mark+1, s.find(')') - mark - 1);
        while(content.find(',', mark+1) != content.npos){
            std::string tmp = std::string(s, mark+1, s.find(',', mark+1) - mark - 1);
            if(strncmp(tmp.c_str(), "Type", 4) == 0){
                type = 0;
                for(int j = 5; j<tmp.length(); j++){
                    if(tmp[j]>= '0' && tmp[j] <= '9')
                        type += type*10 + tmp[j]-'0';
                }
            }
            else if(strncmp(tmp.c_str(), "Code", 4) == 0){
                code = 0;
                for(int j = 5; j<tmp.length(); j++){
                    if(tmp[j]>= '0' && tmp[j] <= '9')
                        code += code*10 + tmp[j]-'0';
                }
            }
            mark = content.find(',', mark+1);
        }
        if(type != -1)
            icmpMatch.setType(type);
        if(code != -1)
            icmpMatch.setCode(code);
        this->matches.setIcmp(icmpMatch);
        return ;
    }
    else{//srcPortRange
        readPortRange(std::string(s, mark, s.find('>')), &srcPortRange);
        mark = s.find('>');
    }
    //destPortRange
    if(s[mark+1] == '*'){
        //ANY destPort
    }
    else{
        if(s.find('(') == s.npos){
            //no Condition
            readPortRange(std::string(s, mark+1, s.length() -1), &destPortRange);
        }
        else{
            readPortRange(std::string(s, mark+1, s.find('(') - mark - 1), &destPortRange);
            mark = s.find('(');
        }
    }
    if(s.find('(') != s.npos){
        content = std::string(s, mark+1, s.find(')') - mark - 1);
        while(content.find(',', mark+1) != content.npos){
            std::string tmp = std::string(s, mark+1, s.find(',', mark+1) - mark - 1);
            if(strncmp(tmp.c_str(), "Length", 6) == 0){
                this->l4 = UDP;
            }
            else if((op = readOp(tmp)) != -1){
                this->l4 = TCP;
                int j=0;
                switch(op){
                case 1:
                    j=3;//NOT
                    break;
                case 2:
                    j=5;//MATCH
                    break;
                case 9:
                    j=6;//NOTANY
                    break;
                case 10:
                    j=8;//NOTMATCH
                    break;
                default:
                    j=tmp.length();//last letter
                    EV_ERROR <<"readL3(): Wrong L4 Condition Op! Check your Rule!";
                    return ;
                }
                for(j; j<tmp.length(); j++){
                    if(tmp[j] >= '0' && tmp[j] <= '9')
                        bitmask += bitmask*10 + (tmp[j]-'0');
                    else{
                        EV_ERROR <<"readL4(): Wrong L4 Condition bitmask! Check your Rule!";
                        return ;
                    }
                }
            }
            else{
                EV_ERROR << "readL4(): Wrong L4 Condition! Check your Rule!";
            }
            mark = content.find(',', mark+1);
        }
        if(this->l4 == UDP){
            if(length != 0)
                udpMatch.setLength(length);
            if(!isPortRangeUnspecified(srcPortRange))
                udpMatch.setSrcPortRange(srcPortRange);
            if(!isPortRangeUnspecified(destPortRange))
                udpMatch.setDestPortRange(destPortRange);
            this->matches.setUdp(udpMatch);
        }
        else{//UNSET and TCP
            if(op != 0){
                tcpMatch.setOp(op);
                tcpMatch.setBitmask(bitmask);
            }
            if(!isPortRangeUnspecified(srcPortRange))
                tcpMatch.setSrcPortRange(srcPortRange);
            if(!isPortRangeUnspecified(destPortRange))
                tcpMatch.setDestPortRange(destPortRange);
            this->matches.setTcp(tcpMatch);
        }
    }
}

uint8_t FilterRule::readOp(std::string s) {
    //enum OpValue{    3    2    1    0
    // ANY = 1; }      8    4    2    1
    // MATCH = 2;     NOT      MATCH ANY
    // NOT_ANY = 9;
    // NOT_MATCH = 10;
    //};
    if(strncmp(s.c_str(),"ANY",3)){
        return 1;
    }
    if(strncmp(s.c_str(),"MATCH",5)){
        return 2;
    }
    if(strncmp(s.c_str(),"NOTANY",6)){
        return 9;
    }
    if(strncmp(s.c_str(),"NOTMATCH",8)){
        return 10;
    }
    return -1;
}

void FilterRule::readPortRange(std::string s, PortRange *pr){
    int portNum = 0, i;
    if(s[0]>='0' && s[0]<='9'){//begin with digit
        for(i = 0; s[i]>='0' && s[i]<='9' && i<s.length(); i++){
            portNum=portNum*10 + (s[i] - '0');
        }
        pr->lowerPort = portNum;
        if(s[i] == '-'){
            portNum=0;
            for(i+=1 ; s[i]>='0' && s[i]<='9' && i<s.length();i++){
                portNum=portNum*10 + (s[i] - '0');
            }
            pr->upperPort = portNum;
            if(pr->lowerPort>=pr->upperPort){
                EV_INFO << "parseExpression() : lowerPort is larger than upperPort";
                return ;
            }
        }
        else{
            pr->op=EQ;
            return ;
        }
    }
    else if(s[0] == '>' || s[0] == '<' || s[0] == '!'){//begin with op
        pr->upperPort=-1;
        switch(s[0]){
        case '>':
            pr->op=GTE;
            break;
        case '<':
            pr->op=LTE;
            break;
        case '!':
            pr->op=NEQ;
            break;
        default:
            EV_INFO << "readPortRange() : wrong op in srcPortRange";
            return ;
        }
        for(i=2 ; s[i]>='0' && s[i]<='9' && i<s.length();i++){
            portNum=portNum*10 + (s[i] - '0');
        }
        pr->lowerPort = portNum;
    }
    else{
        EV_INFO << "readPortRange() : wrong op in srcPortRange";
        return ;
    }
}

void FilterRule::readFilterRule(std::string s) {
    int mark = 0;
    /* state:  0 action
     *         1 srcAddr
     *         2 destAddr
     *         3 l3 Condition
     *         4 srcPort
     *         5 destPort
     *         6 l4 Condition
     * example : ACCEPT; 1.1.1.1 > 2.2.2.2 ( length = 56 ); * > 80 (NOT MATCH 20)
    */
    std::string::iterator it;
    for(it = s.begin(); it < s.end() ; it++)//remove all spaces
        if(*it == ' ')
            s.erase(it--);

    if(s.length()<12){
        EV_ERROR << "readFilterRule(): Length Less Then Min Length! Check your Rule!";
        return ;
    }
    std::string tmp;
    //Action
    readAction(std::string(s, mark, s.find(';', mark)));
    mark = s.find(';' ,mark + 1);
    //l3
    readL3(std::string(s, mark+1, s.find(';',mark+1) - mark -1 ));
    mark = s.find(';', mark + 1);
    //l4
    readL4(std::string(s, mark+1, s.find(';',mark+1) - mark -1 ));
    mark = s.find(';', mark + 1);
}

std::string FilterRule::ipv4MatchStr(Ipv4Match m) const{
    std::stringstream out;
    out << (m.getSrcNetwork().isUnspecified() ? "*" :m.getSrcNetwork().str()) << " > " << (m.getDestNetwork().isUnspecified()? "*" :m.getDestNetwork().str());
    //Check Conditions
    if(m.getLength() == 0 && m.getProtocol() == 0 && m.getFragmentOp() == 0 && m.getFragmentType() == 0){
        out << " :";//No Extra Conditions
    }
    else{//With Conditions
        out << " (";
        int numCdt=0;
        if(m.getLength() != 0){ // length Condition
            out << "Length=%d",m.getLength();
            numCdt++;
        }
        if(m.getProtocol() != 0){ // Protocol Condition
            out << (numCdt == 0 ? "" : ", ") << "Protocol=%d", m.getLength();
            numCdt++;
        }
        uint8_t op = m.getFragmentOp();
        uint8_t type = m.getFragmentType();
        if(op != 0){ // with Fragment Condition
            out << (numCdt == 0 ? "" : ", ") ;
            //fragmentOp
            out << (op & (1<<3)? "NOT" : "") << (op & (1<<1) ? " MATCH" : "") << (op & 1 ? " ANY": "");
                    //fragmentType
            out << (type & (1<<3) ? " df" : "") << (type & (1<<2) ? " isf": "") << (type & (1<<1) ? " ff" : "") << (type & 1 ? " lf": "");
        }
        out << ") ";
    }
    return out.str();
}
std::string FilterRule::ipv6MatchStr(Ipv6Match m) const{
    std::stringstream out;
    out << (m.getSrcNetwork().isUnspecified() ? "*" : m.getSrcNetwork().str()) << " > " << (m.getDestNetwork().isUnspecified()? "*" :m.getDestNetwork().str());
    //Check Conditions
    if(m.getLength() == 0 && m.getProtocol() == 0 && m.getFragmentOp() == 0 && m.getFragmentType() == 0){
        out << " ;";//No Extra Conditions
    }
    else{//With Conditions
        out << " (";
        int numCdt=0;
        if(m.getLength() != 0){ // length Condition
            out << "Length=" << m.getLength();
            numCdt++;
        }
        if(m.getProtocol() != 0){ // Protocol Condition
            out << (numCdt == 0 ? "" : ", ") << "protocol=" << m.getLength();
            numCdt++;
        }
        uint8_t op = m.getFragmentOp();
        uint8_t type = m.getFragmentType();
        if(op != 0){ // with Fragment Condition
            out << (numCdt == 0 ? "" : ", ") ;
            //fragmentOp
            out << (op & (1<<3)? "NOT" : "") << (op & (1<<1) ? " MATCH" : "") << (op & 1 ? " ANY": "");
            //fragmentType
            out << (type & (1<<3) ? " df" : "") << (type & (1<<2) ? " isf": "") << (type & (1<<1) ? " ff" : "") << (type & 1 ? " lf": "");
        }
        out << ") ";
    }
    return out.str();
}
std::string FilterRule::portRangeStr(PortRange pr) const{
    std::stringstream out;
    switch(pr.op){
    case LTE:
        out << "LTE " << pr.lowerPort;
        break;
    case GTE:
        out << "GTE" << pr.lowerPort;
        break;
    case EQ:
        out << pr.lowerPort;
        break;
    case NEQ:
        out << "NEQ" << pr.lowerPort;
        break;
    default: //NO_OP
        out << pr.lowerPort <<"-"<< pr.upperPort;
        break;
    }
    return out.str();
}

std::string FilterRule::tcpMatchStr(TcpMatch tm) const{
    std::stringstream out;
    out << portRangeStr(tm.getSrcPortRange()) << " > " << portRangeStr(tm.getDestPortRange());
    uint8_t op = tm.getOp();
    if(op != 0){
        out <<"(" <<(op & (1<<3)? "NOT" : "") << (op & (1<<1) ? " MATCH" : "") << (op & 1 ? " ANY": "");
        out << tm.getBitmask() << ")";
    }
    return out.str();
}

std::string FilterRule::udpMatchStr(UdpMatch um) const{
    std::stringstream out;
    out << portRangeStr(um.getSrcPortRange()) << " > " << portRangeStr(um.getDestPortRange());
    if(um.getLength() != 0 ){
        out << "(length=" << um.getLength() << ")";
    }
    return out.str();
}

std::string FilterRule::icmpMatchStr(IcmpMatch im) const{
    std::stringstream out;
    if(im.getType() == 0 && im.getCode() == 0){
        return out.str();
    }
    else {
        out << "(" ;
        if(im.getType() != 0 && im.getCode() != 0)
            out << "Code = " << im.getCode() << ", Type = " << im.getType();
        else{
            if(im.getType() != 0)
                out << "Type = " << im.getType();
            else
                out << "Code = " << im.getCode();
        }
        out << ")";
    }
    return out.str();
}

std::string FilterRule::str() const{
    std::stringstream out;
    if(action.getForwarding() == ACCEPT){
        out << "ACCEPT;";
    }
    else if(action.getForwarding() == DROP){
        out << "DROP;";
    }
    else if(action.getForwarding() == RATE_LIMIT){
        out << "RATE_LIMIT " << action.getRateLimit();
    }
    else if(action.getForwarding() == MATCH){
        out << "MATCH;";
    }

    if(l3 == IPV4){
        out << ipv4MatchStr(matches.getIpv4()) << ";";
    }
    else{ // IPV6
        out << ipv6MatchStr(matches.getIpv6()) << ";";
    }
    if(l4 == TCP)
        out << tcpMatchStr(matches.getTcp());
    else if(l4 == UDP)
        out << udpMatchStr(matches.getUdp());
    else// l4 == ICMP
        out << icmpMatchStr(matches.getIcmp());
    return out.str();
}

std::string FilterRule::detailedInfo() const {
    return std::string();
}

bool FilterRule::matchIpv4Packet(Packet * packet) const {
    ASSERT(packet);
    if(this->l3 == IPV6)
        return false;
    const auto& ipv4Header = packet->popAtFront<Ipv4Header>();
    Ipv4Address srcAddr = ipv4Header->getSrcAddress();
    Ipv4Address destAddr = ipv4Header->getDestAddress();
    Ipv4Match m = this->matches.getIpv4();
    if(!srcAddr.isUnspecified() && srcAddr.isNetwork(m.getSrcNetwork()))
        return false;
    if(!destAddr.isUnspecified() && destAddr.isNetwork(m.getDestNetwork()))
        return false;
    if(packet->getBitLength() != m.getLength() && m.getLength() != 0 )
        return false;
    if(ipv4Header->getProtocolId() != m.getProtocol() && m.getProtocol() != 0)
        return false;
    //if( fragment condition )

    //IP_PROT_ICMP = 1, IP_PROT_TCP = 6, IP_PROT_UDP = 17
    if(ipv4Header->getProtocolId() == IP_PROT_ICMP)
        return matchIcmpPacket(packet);
    else if(ipv4Header->getProtocolId() == IP_PROT_TCP)
        return matchTcpPacket(packet);
    else if(ipv4Header->getProtocolId() == IP_PROT_UDP)
        return matchUdpPacket(packet);
    else
        return false;
}

bool FilterRule::matchIpv6Packet(Packet *packet) const {
    ASSERT(packet);
    if(this->l3 == IPV4)
        return false;
    const auto& ipv6Header = packet->popAtFront<Ipv6Header>();
    Ipv6Address srcAddr = ipv6Header->getSrcAddress();
    Ipv6Address destAddr = ipv6Header->getDestAddress();
    Ipv6Match m = this->matches.getIpv6();

    //if(!srcAddr.isUnspecified() && srcAddr.matches(m.getSrcNetwork()))

    if(packet->getBitLength() != m.getLength() && m.getLength() != 0 )
        return false;
    if(ipv6Header->getProtocolId() != m.getProtocol())
        return false;
    //if (fragment condition)

    if(ipv6Header->getProtocolId() == IP_PROT_ICMP)
        return matchIcmpPacket(packet);
    else if(ipv6Header->getProtocolId() == IP_PROT_TCP)
        return matchTcpPacket(packet);
    else if(ipv6Header->getProtocolId() == IP_PROT_UDP)
        return matchUdpPacket(packet);
    else
        return false;
}

bool FilterRule::isPortRangeUnspecified(PortRange pr) const{
    if( pr.op == NO_OP && pr.lowerPort == 0 && pr.upperPort == 0)
        return true;
    return false;
}

bool FilterRule::matchTcpPacket(Packet *packet) const{
    auto tcpHeader = packet->peekAtFront<TcpHeader>();

    TcpMatch m = this->matches.getTcp();
    if(!inPortRange(tcpHeader->getSrcPort(), m.getSrcPortRange()) && !isPortRangeUnspecified(m.getSrcPortRange()))
        return false;
    if(!inPortRange(tcpHeader->getDestPort() ,m.getDestPortRange()) && !isPortRangeUnspecified(m.getDestPortRange()))
        return false;
    //enum OpValue{    3    2    1    0
    // ANY = 1; }      8    4    2    1
    // MATCH = 2;     NOT      MATCH ANY
    // NOT_ANY = 9;
    // NOT_MATCH = 10;
    //};
    uint16_t flags = getTcpFlags(tcpHeader);
    switch(m.getOp()){
    case 1: //ANY
        if(((flags & m.getBitmask()) == 0 ))
            return false;
    case 2: //MATCH
        if(((flags & m.getBitmask()) != m.getBitmask()))
            return false;
    case 9: //NOT ANY
        if((flags & m.getBitmask()) != 0 )
            return false;
    case 10://NOT MATCH
        if((flags & m.getBitmask()) == m.getBitmask())
            return false;
    default://NO_OP and bitmask
        break;
    }
    return true;
}

bool FilterRule::matchUdpPacket(Packet *packet) const{
    auto udpHeader = packet->peekAtFront<UdpHeader>();
    UdpMatch m = this->matches.getUdp();
    if(!inPortRange(udpHeader->getSrcPort() ,m.getSrcPortRange()) && !isPortRangeUnspecified(m.getSrcPortRange()))
        return false;
    if(!inPortRange(udpHeader->getDestPort() ,m.getDestPortRange()) && !isPortRangeUnspecified(m.getDestPortRange()))
        return false;
    if(m.getLength() != 0 && packet->getBitLength()/8+8 != m.getLength())
        return false;
    return true;
}

bool FilterRule::matchIcmpPacket(Packet *packet) const{
    auto icmpHeader = packet->peekAtFront<IcmpHeader>();
    IcmpMatch m = this->matches.getIcmp();
    if( m.getCode() != icmpHeader->getCode() && m.getCode() != -1)
        return false;
    if( m.getType() != icmpHeader->getType() && m.getType() != -1)
        return false;
    return true;
}

bool FilterRule::inPortRange(uint16_t portNum, PortRange pr) const{
    switch(pr.op){
    case NO_OP:
        return (portNum >= pr.lowerPort && portNum <= pr.upperPort) ? true : false;
    case LTE:
        return (portNum <= pr.lowerPort) ? true : false;
    case GTE:
        return (portNum <= pr.lowerPort) ? true : false;
    case EQ:
        return (portNum == pr.lowerPort) ? true : false;
    case NEQ:
        return (portNum != pr.lowerPort) ? true : false;
    default:
        return false;
    }
}

uint16_t FilterRule::getTcpFlags(Ptr<const TcpHeader> h) const {
    uint16_t flags = 0;
    if (h->getCwrBit())
        flags += (1<<7);
    if (h->getEceBit())
        flags += (1<<6);
    if (h->getUrgBit())
        flags += (1<<5);
    if (h->getSynBit())
        flags += (1<<4);
    if (h->getAckBit())
        flags += (1<<3);
    if (h->getPshBit())
        flags += (1<<2);
    if (h->getRstBit())
        flags += (1<<1);
    if (h->getFinBit())
        flags += 1;
    return flags;
}

}//namespace inet
