/*
 * FilterRuleTable.cc
 *
 *  Created on: 2020��9��15��
 *      Author: QianCheng
 */

#include "inet/_extra/networklayer/FilterRuleTable.h"

namespace inet {

Define_Module(FilterRuleTable);

void FilterRuleTable::initialize(int stage){
    cSimpleModule::initialize(stage);

}

void FilterRuleTable::handleMessage(cMessage *msg){

}

void FilterRuleTable::addFilterRule(FilterRule * entry){

}

bool FilterRuleTable::matchPacket(Packet * packet);
    return false;
}


