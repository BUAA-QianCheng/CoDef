//
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

import inet._extra.networklayer.FilterRule;

namespace inet;

class Statistics{
	long matchedPackets;
	long matchedOctets;
}

class Ace{
	string name;
	Matches matches;
	Action action;
	Statistics statistics;
}

enum ActivationType{
	ACTIVITE_WHEN_MITIGATING = 1; //The ACLs is installed only when a mitigation is active for the client.
	IMMEDIATE = 2; //The ACL is immediately activated.
	DEACTIVATE = 3; //The ACL is maintained by the DOTS server, but it isdeactivated.
}


class Acl{
	string name;
	string type;
	ActivationType activitionType;
	int PendingLifetime;
	Ace ace[];	
}

class Acls{
	Acl acls[];
}