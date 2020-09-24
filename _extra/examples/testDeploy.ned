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

package inet._extra.examples;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.visualizer.integrated.IntegratedVisualizer;
import inet.node.ethernet.Eth100M;
import inet.node.ethernet.EtherSwitch;
import inet.node.inet.StandardHost;
import inet.node.inet.Router;


network TestL3Deploy
{
    parameters:

    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=50,30");
        }
        visualizer: IntegratedVisualizer {
            @display("p=50,90");
        }
        sendhost: StandardHost {
            @display("p=150,30");
        }
        recvhost: StandardHost {
            @display("p=150,210");
        }
        router1: Router {
            @display("p=150,90");
        }
        router2: Router {
            @display("p=150,150");
        }
        mitigator: Router {
            @display("p=250,90");
        }
    connections:
        sendhost.ethg++ <--> Eth100M <--> router1.ethg++;
        router1.ethg++ <--> Eth100M <--> router2.ethg++;
        router2.ethg++ <--> Eth100M <--> recvhost.ethg++;
        router1.ethg++ <--> Eth100M <--> mitigator.ethg++;
        router1.ethg++ <--> Eth100M <--> mitigator.ethg++;
}

network TestL2Deploy
{
    parameters:

    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=50,30");
        }
        visualizer: IntegratedVisualizer {
            @display("p=50,90");
        }
        sendhost: StandardHost {
            @display("p=150,30");
        }
        recvhost: StandardHost {
            @display("p=150,210");
        }
        switch1: EtherSwitch {
            @display("p=150,90");
        }
        router1: Router {
            @display("p=150,150");
        }
        mitigator: Router {
            @display("p=250,90");
        }
    connections:
        sendhost.ethg++ <--> Eth100M <--> switch1.ethg++;
        switch1.ethg++ <--> Eth100M <--> mitigator.ethg++;
        switch1.ethg++ <--> Eth100M <--> mitigator.ethg++;
        switch1.ethg++ <--> Eth100M <--> router1.ethg++;
        recvhost.ethg++ <--> Eth100M <--> router1.ethg++;    
}
