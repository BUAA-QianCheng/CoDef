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

import inet.node.inet.Router;
import inet._extra.applications.defencebox.DefenceBox;
import inet.node.ethernet.Eth100M;

module RouterWithFirewall
{
    parameters:
        @networkNode();
        @display("i=abstract/opticalrouter");
    gates:
        inout ethg[] @labels(EtherFrame-conn) @allowUnconnected;
        inout pppg[] @labels(PppFrame-conn) @allowUnconnected;

    submodules:
        router: Router {
            numEthInterfaces = sizeof(ethg);  // minimum number of ethernet interfaces
       		numPppInterfaces = sizeof(pppg);  // minimum number of PPP interfaces
            @display("p=120,30");
        }
        defBox: DefenceBox {
            numEthInterfaces = sizeof(ethg);  // minimum number of ethernet interfaces
       		numPppInterfaces = sizeof(pppg);  // minimum number of PPP interfaces
            @display("p=120,120");
        }
	connections allowunconnected:
        for i=0..sizeof(ethg)-1 {
            ethg[i] <--> defBox.ethgin[i];
        	defBox.ethgout[i] <--> Eth100M <--> router.ethg[i];
        }
        for i=0..sizeof(pppg)-1 {
            pppg[i] <--> defBox.pppgin[i];
        	defBox.pppgout[i] <--> Eth100M <--> router.pppg[i];            
        }
}
