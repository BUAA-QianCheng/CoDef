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

package inet._extra.transportlayer;

//transportlayer module for generating DDoS Attack packets



simple PacketGenerator{
	parameters:
	    string localAddr = default("");
        string destAddr = default("");
        int localPort;
        int destPort;
        double startTime @unit(s) = default(this.sendInterval); 
        double stopTime @unit(s) = default(-1s);
        string packetName;
	    string packetType @enum("TCP_SYN", "TCP_SYNACK", "TCP_ACK", "TCP_RST", "UDP", "ICMP");
	    volatile double sendInterval @unit(s);
	    @display("i=block/rightarrow");
	gates:
        input ipIn;
        output ipOut;
}
