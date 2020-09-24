
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

import inet.networklayer.contract.ipv4.Ipv4Address;
import inet.networklayer.contract.ipv6.Ipv6Address;
import inet._extra.transportlayer.PortRange;

namespace inet;

//class MatchOp{
//	bool NOT;
//	bool MATCH;
//	bool ANY;
//}
//
//class FragmentType{
//	bool df; //Don't Fragment
//	bool isf; //Is a Fragment
//	bool ff; //First Fragment
//	bool lf; //Last Fragment
//}
//enum OpValue{
// ANY = 1; 
// MATCH = 2;
// NOT_ANY = 9;
// NOT_MATCH = 10;
//};

class Ipv4Match{
	uint16_t length;
	uint8_t protocol;
	Ipv4Address destNetwork;
	Ipv4Address srcNetwork;
	uint8_t fragmentOp;
	uint8_t fragmentType;
}

class Ipv6Match{
	uint16_t length;
	uint8_t protocol;
	Ipv6Address destNetwork;
	Ipv6Address srcNetwork;
	uint8_t fragmentOp;
	uint8_t fragmentType;
}

class TcpMatch{
	uint8_t op;
	uint16_t bitmask;
	PortRange srcPortRange;
	PortRange destPortRange;
}

class UdpMatch{
	uint16_t length;
	PortRange srcPortRange;
	PortRange destPortRange;
}

class IcmpMatch{
	int8_t type = -1;
	int8_t code = -1;
}

class Matches{
	Ipv4Match ipv4;
	Ipv6Match ipv6;
	TcpMatch tcp;
	UdpMatch udp;
	IcmpMatch icmp;
}

enum ForwardingActions{
	MATCH = 0;
	ACCEPT = 1;
	DROP = 2;
	RATE_LIMIT = 3;
}

class Action{
	ForwardingActions forwarding;
	double rateLimit;	
}