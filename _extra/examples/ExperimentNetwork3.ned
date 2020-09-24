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

import inet._extra.node.Mitigator;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.inet.AdhocHost;
import inet.node.inet.WirelessHost;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;
import inet.node.ethernet.EtherSwitch;
import inet.node.internetcloud.InternetCloud;
import inet.visualizer.integrated.IntegratedVisualizer;
import inet._extra.linklayer.Splitter;
import inet._extra.node.Detector;
import inet.linklayer.ethernet.EtherHub;
import inet.node.ethernet.Eth100M;
import inet.node.inet.StandardHost;
import inet.node.inet.Router;
import inet._extra.node.DDoSBot;
import inet.node.wireless.AccessPoint;

module WirelessNetwork
{
    gates:
        inout pppg[];
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
        ap: AccessPoint {
            @display("p=180,90");
        }
        wirelessHost: WirelessHost {
            @display("p=220,160");
        }
        mobileHost: WirelessHost {
            @display("p=140,160;i=misc/smartphone");
        }
        router: Router {
            @display("p=270,30");
        }
        mecNode: StandardHost {
            @display("p=360,90;i=device/server");
        }
    connections:
        pppg++ <--> router.pppg++;
        ap.ethg++ <--> Eth100M <--> router.ethg++;
        mecNode.ethg++ <--> Eth100M <--> router.ethg++;
}

module WiredNetwork
{
    gates:
        inout pppg[];
    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=50,30");
        }
        visualizer: IntegratedVisualizer {
            @display("p=50,90");
        }
        router: Router {
            @display("p=200,40");
        }
        switch1: EtherSwitch {
            @display("p=140,130");
        }
        switch2: EtherSwitch {
            @display("p=260,130");
        }
        host1: StandardHost {
            @display("p=100,240");
        }
        host2: StandardHost {
            @display("p=170,240");
        }
        host3: StandardHost {
            @display("p=230,240");
        }
        bot: DDoSBot {
            @display("p=300,240");
        }
    connections:
        pppg++ <--> router.pppg++;
        host1.ethg++ <--> Eth100M <--> switch1.ethg++;
        host2.ethg++ <--> Eth100M <--> switch1.ethg++;
        host3.ethg++ <--> Eth100M <--> switch2.ethg++;
        bot.ethg++ <--> Eth100M <--> switch2.ethg++;
        switch1.ethg++ <--> Eth100M <--> router.ethg++;
        switch2.ethg++ <--> Eth100M <--> router.ethg++;
}


module CloudCenter
{
    gates:
        inout pppg[];
    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=50,30");
        }
        visualizer: IntegratedVisualizer {
            @display("p=50,90");
        }
        coreRouter: Router {
            @display("p=200,40");
        }
        mitigator: Router {
            @display("p=200,110;i=device/server");
        }
        collectRouter: Router {
            @display("p=200,190");
        }
        connectSwitch1: EtherSwitch {
            @display("p=120,260");
        }
        connectSwitch2: EtherSwitch {
            @display("p=280,260");
        }
        server1: StandardHost {
            @display("p=70,330");
        }
        server2: StandardHost {
            @display("p=150,330");
        }
        server3: StandardHost {
            @display("p=240,330");
        }
        server4: StandardHost {
            @display("p=320,330");
        }
    connections:
        pppg++  <--> coreRouter.pppg++;
        server1.ethg++ <--> Eth100M <--> connectSwitch1.ethg++;
        server2.ethg++ <--> Eth100M <--> connectSwitch1.ethg++;
        server3.ethg++ <--> Eth100M <--> connectSwitch2.ethg++;
        server4.ethg++ <--> Eth100M <--> connectSwitch2.ethg++;
        connectSwitch1.ethg++ <--> Eth100M <--> collectRouter.ethg++;
        connectSwitch2.ethg++ <--> Eth100M <--> collectRouter.ethg++;
        mitigator.ethg++ <--> Eth100M <--> collectRouter.ethg++;
        mitigator.ethg++ <--> Eth100M <--> coreRouter.ethg++;
}


network ExperimentNetwork3
{
    parameters:

    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=50,30");
        }
        InternetCloud: Router {
            @display("p=280,150;i=misc/cloud_vl");
        }
        CloudCenter: CloudCenter {
            @display("p=440,80;i=misc/cloud_l");
        }
        WiredNetwork1: WiredNetwork {
            @display("p=200,60;i=block/network2_l");
        }
        WiredNetwork2: WiredNetwork {
            @display("p=360,240;i=block/network2_l");
        }
        WirelessNetwork: WirelessNetwork {
            @display("p=120,220;i=block/wrx_l");
        }
    connections:
        InternetCloud.pppg++ <--> Eth100M <--> CloudCenter.pppg++;
        InternetCloud.pppg++ <--> Eth100M <--> WiredNetwork1.pppg++;
        InternetCloud.pppg++ <--> Eth100M <--> WiredNetwork2.pppg++;
        InternetCloud.pppg++ <--> Eth100M <--> WirelessNetwork.pppg++;
}
