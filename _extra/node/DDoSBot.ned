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

package inet._extra.node;

import inet.node.inet.StandardHost;
import inet._extra.transportlayer.PacketGenerator;

module DDoSBot extends StandardHost
{
    parameters:
        @display("i=_extra/bot");
        int numPktGen = default(0);
    submodules:
        pg[numPktGen]: PacketGenerator {
            @display("p=825,226");
        }
    connections:
        for i=0..numPktGen-1 {
            pg[i].ipOut --> tn.in++;
            pg[i].ipIn <-- tn.out++;
        }
}
