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

import inet._extra.linklayer.Splitter;
import inet._extra.node.DDoSBot;
import inet._extra.node.Detector;
import inet._extra.node.Mitigator;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.Eth100M;
import inet.node.inet.WirelessHost;
import inet.node.wireless.AccessPoint;
import inet.visualizer.integrated.IntegratedVisualizer;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;
import inet.node.ethernet.EtherSwitch;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;


network PCE_Environment
{
    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=50,30");
        }
        visualizer: IntegratedVisualizer {
            @display("p=50,90");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            @display("p=50,150");
        }
        accessPoint: AccessPoint {
            @display("p=181,489");
        }
        clientAgent1: StandardHost {
            @display("p=274,396;i=block/app2");
        }
        clientAgent2: StandardHost {
            @display("p=575,161;i=block/app2");
        }
        cloudServer1: StandardHost {
            @display("p=637,571;i=device/lan-ring");
        }
        cloudServer2: StandardHost {
            @display("p=734,595;i=device/lan-ring");
        }
        cloudServer3: StandardHost {
            @display("p=837,582;i=device/lan-ring");
        }
        cloudServer4: StandardHost {
            @display("p=918,543;i=device/lan-ring");
        }
        cloudServer5: StandardHost {
            @display("p=966,452;i=device/lan-ring");
        }
        cloudServer6: StandardHost {
            @display("p=966,361;i=device/lan-ring");
        }
        ddosBot1: DDoSBot {
            @display("p=258,90");
        }
        ddosBot2: DDoSBot {
            @display("p=617,69");
        }
        detectionAgent1: Detector {
            @display("p=419,507");
        }
        detectionAgent2: Detector {
            @display("p=360,230");
        }
        etherSwitch1: EtherSwitch {
            @display("p=274,489");
        }
        etherSwitch2: EtherSwitch {
            @display("p=338,154");
        }
        etherSwitch3: EtherSwitch {
            @display("p=497,122");
        }
        mecNode: StandardHost {
            @display("p=338,565");
        }
        mitigationAgent1: Mitigator {
            @display("p=705,327;i=device/server");
        }
        mitigationAgent2: Mitigator {
            @display("p=354,361;i=device/server");
        }
        mitigationAgent3: Mitigator {
            @display("p=559,233;i=device/server");
        }
        mobileHost: WirelessHost {
            @display("p=89,529;i=misc/smartphone");
        }
        router1: Router {
            @display("p=420,406");
        }
        router2: Router {
            @display("p=474,252");
        }
        router3: Router {
            @display("p=637,375");
        }
        router4: Router {
            @display("p=739,406");
        }
        router5: Router {
            @display("p=739,508");
        }
        router6: Router {
            @display("p=861,448");
        }
        serverAgent: StandardHost {
            @display("p=656,456;i=block/app2");
        }
        splitter1: Splitter {
            @display("p=348,448");
        }
        splitter2: Splitter {
            @display("p=435,186");
        }
        standardHost1: StandardHost {
            @display("p=202,138");
        }
        standardHost2: StandardHost {
            @display("p=338,60");
        }
        standardHost3: StandardHost {
            @display("p=442,36");
        }
        standardHost4: StandardHost {
            @display("p=536,36");
        }
        wirelessHost: WirelessHost {
            @display("p=89,448");
        }

    connections:
        accessPoint.ethg++ <--> Eth100M <--> etherSwitch1.ethg++;
        clientAgent1.ethg++ <--> Eth100M <--> etherSwitch1.ethg++;
        mecNode.ethg++ <--> Eth100M <--> etherSwitch1.ethg++;
        etherSwitch1.ethg++ <--> Eth100M <--> splitter1.ethg++;
        detectionAgent1.ethg++ <--> Eth100M <--> splitter1.ethg++;
        router1.ethg++ <--> Eth100M <--> splitter1.ethg++;
        router1.ethg++ <--> Eth100M <--> router2.ethg++;
        router1.ethg++ <--> Eth100M <--> router3.ethg++;
        router2.ethg++ <--> Eth100M <--> router3.ethg++;
        standardHost1.ethg++ <--> Eth100M <--> etherSwitch2.ethg++;
        standardHost2.ethg++ <--> Eth100M <--> etherSwitch2.ethg++;
        standardHost3.ethg++ <--> Eth100M <--> etherSwitch3.ethg++;
        standardHost4.ethg++ <--> Eth100M <--> etherSwitch3.ethg++;
        clientAgent2.ethg++ <--> Eth100M <--> etherSwitch3.ethg++;
        ddosBot1.ethg++ <--> Eth100M <--> etherSwitch2.ethg++;
        ddosBot2.ethg++ <--> Eth100M <--> etherSwitch3.ethg++;
        etherSwitch2.ethg++ <--> Eth100M <--> splitter2.ethg++;
        etherSwitch3.ethg++ <--> Eth100M <--> splitter2.ethg++;
        splitter2.ethg++ <--> Eth100M <--> router2.ethg++;
        detectionAgent2.ethg++ <--> Eth100M <--> splitter2.ethg++;
        cloudServer1.ethg++ <--> Eth100M <--> router5.ethg++;
        cloudServer2.ethg++ <--> Eth100M <--> router5.ethg++;
        cloudServer3.ethg++ <--> Eth100M <--> router5.ethg++;
        cloudServer4.ethg++ <--> Eth100M <--> router6.ethg++;
        cloudServer5.ethg++ <--> Eth100M <--> router6.ethg++;
        cloudServer6.ethg++ <--> Eth100M <--> router6.ethg++;
        router5.ethg++ <--> Eth100M <--> router4.ethg++;
        router6.ethg++ <--> Eth100M <--> router4.ethg++;
        mitigationAgent1.ethg++ <--> Eth100M <--> router3.ethg++;
        router4.ethg++ <--> Eth100M <--> router3.ethg++;
        serverAgent.ethg++ <--> Eth100M <--> router4.ethg++;
        mitigationAgent2.ethg++ <--> Eth100M <--> router1.ethg++;
        mitigationAgent3.ethg++ <--> Eth100M <--> router2.ethg++;
}
