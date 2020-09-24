/*
 * PacketMatchExpression.cc
 *
 *  Created on: 2020Äê9ÔÂ6ÈÕ
 *      Author: bjche
 */




#include "inet/_extra/common/packet/PacketMatchExpression.h"
#include <stdio.h>
#include <math.h>
namespace inet{

using namespace std;

bool PacketMatchExpression::isMark(char c){
    switch(c){
    case ':':
    case ',':
    case '>':
    case '(':
    case ')':
    case '?':
        return true;
    default:
        return false;
    }
}

PortRange PacketMatchExpression::readPortRange(string s){
    PortRange pr = PortRange();
    int portNum = 0, i;
    if(s[0]>='0' && s[0]<='9'){
        for(i = 0; s[i]>='0' && s[i]<='9' && i<s.length();i++){
            portNum=portNum*10 + (s[i] - '0');
        }
        pr.lowerPort = portNum;
        portNum=0;
        for(i+=1 ; s[i]>='0' && s[i]<='9' && i<s.length();i++){
            portNum=portNum*10 + (s[i] - '0');
        }
        pr.upperPort = portNum;
        if(pr.lowerPort>=pr.upperPort){
            EV_INFO << "parseExpression() : lowerPort is larger than upperPort";
            return pr;
        }
    }
    else{
        pr.upperPort=-1;
        switch(s[0]){
        case '=':
            pr.op=EQ;
            break;
        case '>':
            pr.op=GTE;
            break;
        case '<':
            pr.op=LTE;
            break;
        case '!':
            pr.op=NEQ;
            break;
        default:
            EV_INFO << "praseExpression() : wrong op in srcPortRange";
            return pr;
        }
        for(i=2 ; s[i]>='0' && s[i]<='9' && i<s.length();i++){
            portNum=portNum*10 + (s[i] - '0');
        }
        pr.lowerPort = portNum;
    }
    return pr;
}

void PacketMatchExpression::readAction(string s){
    switch(s[0]){
    case 'M':
        action=MATCH;
        break;
    case 'A':
        action=ACCEPT;
        break;
    case 'D':
        action=DROP;
        break;
    case 'R':
        action=RATE_LIMIT;
        rateLimit=0.0;
        for(int i = 11, dot=0; i<s.length();i++){
            if(s[i] >= '0' && s[i] <= '9' && dot == 0){
                rateLimit = rateLimit*10.0 + (s[i]-'0');
            }
            else if(s[i] >= '0' && s[i] <= '9' && dot == 0){
                rateLimit = rateLimit + pow(0.1, dot)*(s[i]-'0');
                dot++;
            }
            else if(s[i] == '.' && i != 11){
                dot=1;
            }
            else{
                EV_INFO <<"readAction() : wrong rate limit value!";
            }
        }
        break;
    default:
        EV_INFO<<"readAction() : wrong Action!";
        break;
    }
}

void PacketMatchExpression::parseExpression(){
    int  lastMark = 0, len = strlen(expression), state = 0;
    /*state:  0 action
              1 srcAddr
              2 destAddr
              3 l3 Condition
              4 srcPort
              5 destPort
              6 l4 Condition
    example : ACCEPT; 1.1.1.1 > 2.2.2.2 ( length = 56 ); * > 80 (NOT MATCH 20)
    */
    for(int i = 0 ; i < len ; i++){
        if(isMark(expression[i])){
           if(i == 0){
               EV_INFO <<"parseExpression() : There should be a name";
               return ;
           }
           switch(state){
           case 0:{
               if(expression[i] == ':' ){
                   ruleName = string(expression, lastMark, i).c_str();
                   lastMark = i;
                   state = 1;
               }
               else{
                   EV_INFO<<"parseExpression() : Wrong in state 1";
                   return;
               }
               break;
           }
           case 1:{
               if(expression[i] == ','){
                   if(i == lastMark+1){
                       EV_INFO<<"parseExpression() : Wrong grammar in srcAddr of rule:" << ruleName;
                       return ;
                   }
                   srcIpv4AddrList.push_back(Ipv4Address(string(expression, lastMark+1, i-lastMark-1).c_str()));
               }
               else if(expression[i] == '>'){
                   if(lastMark-i > 1){
                       srcIpv4AddrList.push_back(Ipv4Address(string(expression, lastMark+1, i-lastMark-1).c_str()));
                   }
                   state = 2;
               }
               else{
                   EV_INFO<<"parseExpression() : Wrong in state 1";
                   return ;
               }
               lastMark = i;
               break;
           }
           case 2:{
               if(expression[i] == ','){
                   if(i == lastMark+1){
                       EV_INFO<<"PacketMatchExpression::parseExpression() : Wrong grammar in destAddr of rule:" << ruleName;
                       return ;
                   }
                   destIpv4AddrList.push_back(Ipv4Address(string(expression, lastMark+1, i-lastMark-1).c_str()));
               }
               else if(expression[i] == '('){
                   if(lastMark-i > 1){//if there is a addr
                       destIpv4AddrList.push_back(Ipv4Address(string(expression, lastMark+1, i-lastMark-1).c_str()));
                   }
                   state = 3;
               }
               else if(expression[i] == ':'){
                   if(lastMark-i > 1){//if there is a addr
                       destIpv4AddrList.push_back(Ipv4Address(string(expression, lastMark+1, i-lastMark-1).c_str()));
                   }
                   state = 4;
               }
               else{
                   EV_INFO<<"parseExpression() : Wrong in state 2";
                   return ;
               }
               lastMark = i;
               break;
           }
           case 3:{
               if(expression[i] == ','){
                   if(i == lastMark+1){
                       EV_INFO<<"PacketMatchExpression::parseExpression() : Wrong grammar in l3 condition of rule:" << ruleName;
                       return ;
                   }
                   l3ConditionList.push_back(string(expression, lastMark+1, i-lastMark-1));
                   lastMark = i;
               }
               else if(expression[i] == ')'){
                   //parse ':'
                   if(expression[lastMark] == ',' && i == lastMark+1){
                       EV_INFO<<"PacketMatchExpression::parseExpression() : Wrong grammar in l3 condition of rule:" << ruleName;
                       return ;
                   }
                   else if(i - lastMark > 1){
                       l3ConditionList.push_back(string(expression, lastMark+1, i-lastMark-1));
                   }
                   lastMark = i++;
                   state = 4;
               }
               else{
                   EV_INFO<<"parseExpression() : Wrong in state 3";
                   return ;
               }
               break;
           }
           case 4:{
               if(expression[i] == ','){
                   if(i == lastMark+1){
                        EV_INFO<<"parseExpression() : Wrong grammar in srcAddr of rule:" << ruleName;
                        return ;
                   }
                   srcPortList.push_back(readPortRange(string(expression, lastMark+1, i-lastMark-1)));
               }
               else if( expression [i] == '>'){
                   if(lastMark-i > 1){
                       srcPortList.push_back(readPortRange(string(expression, lastMark+1, i-lastMark-1)));
                   }
                   state = 5;
               }
               else{
                   EV_INFO<<"parseExpression() : Wrong in state 4";
                   return ;
               }
               lastMark = i;
               break;
           }
           case 5:{
               if(expression[i] == ','){
                   if(i == lastMark+1){
                       EV_INFO<<"parseExpression() : Wrong grammar in srcAddr of rule:" << ruleName;
                       return ;
                   }
                   destPortList.push_back(readPortRange(string(expression, lastMark+1, i-lastMark-1)));
               }
               else if(expression[i] == '('){
                   if(lastMark-i > 1){
                       destPortList.push_back(readPortRange(string(expression, lastMark+1, i-lastMark-1)));
                   }
                   state = 5;
               }
               else if(expression[i] == '?'){
                   if(lastMark-i > 1){
                       destPortList.push_back(readPortRange(string(expression, lastMark+1, i-lastMark-1)));
                   }
                   readAction(string(expression,i+1,len-i-1));
                   return ; //right exit!
               }
               else{
                   EV_INFO<<"parseExpression() : Wrong in state 5";
               }
               lastMark = i;
               break;
           }
           case 6:{
               if(expression[i] == ','){
                   if(i == lastMark+1){
                       EV_INFO<<"PacketMatchExpression::parseExpression() : Wrong grammar in l4 condition of rule:" << ruleName;
                       return ;
                   }
                   l4ConditionList.push_back(string(expression, lastMark+1, i-lastMark-1));
                   lastMark = i;
               }
               else if(expression[i] == ')'){
                   if(expression[lastMark] == ',' && i == lastMark+1){
                       EV_INFO<<"PacketMatchExpression::parseExpression() : Wrong grammar in l4 condition of rule:" << ruleName;
                       return ;
                   }
                   else if(i - lastMark > 1){
                       l4ConditionList.push_back(string(expression, lastMark+1, i-lastMark-1));
                   }
                   lastMark = i++;
                   readAction(string(expression,i+1,len-i-1));
                   return ;//right exit!
               }
               else{
                   EV_INFO<<"parseExpression() : Wrong in state 6";
               }
               break;
           }
           default:{
               EV_INFO << "parseExpression() : Wrong State!";
               return ;
           }
           }
        }
    }
}

void PacketMatchExpression::setExpression(string exp){
    expression = string(exp).c_str();
    parseExpression();
}

bool PacketMatchExpression::matchExpression(const char* pktExp){
    if(!strcmp(expression,"")){
        EV_INFO <<"Packet Expression is null!";
        return false;
    }
    else{
        return true;
    }
}

}


