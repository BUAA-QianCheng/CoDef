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

import inet.networklayer.contract.ipv4.Ipv4Address;
import inet.common.INETDefs;
import inet.common.packet.chunk.Chunk;
import inet._extra.transportlayer.PortRange;

namespace inet;

//Mitication Scope 
enum MitigationStatus{
	SETUP = 1;
	MITIGATED = 2;
	ATTACK_STOPPED = 3;
	CAPABILITY_EXCEEDED = 4;
	TERMINATING = 5;
	TERMINATED = 6;
	OVERLAPING = 7;
	STANGING_BY = 8;
}

class MitigationTarget extends FieldsChunk{
	Ipv4Address targetPrefix[];
	PortRange portRange[];
	uint8_t targetProtocol[];//uint8
    string targetFqdn[];//inet:domain_name
    string targetUri[];//inet:uri
    string aliasName;//string
}

class MitigationCreate extends MitigationTarget{
    int32_t lifetime;//int32
    bool triggerMitigation;//boolean
}

class MitigationStatistics extends MitigationCreate{
	uint64_t mitigationStart;//uint64
    MitigationStatus status;//iana_signal:status
    long bytesDropped;
    long bpsDropped;
    long pktsDropped;
    long ppsDropped;
}

class MitigationEfficacy extends FieldsChunk{
	bool attackStatus;
}