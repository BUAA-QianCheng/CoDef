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

network ExperimentNetwork2
{
    parameters:

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
        router: Router {
            @display("p=865,388");
        }
        router1: Router {
            @display("p=588,432");
        }
        router2: Router {
            @display("p=787,580");
        }
        router3: Router {
            @display("p=520,615");
        }
        router4: Router {
            @display("p=385,387");
        }
        router5: Router {
            @display("p=903,743");
        }
        router6: Router {
            @display("p=382,595");
        }
        router7: Router {
            @display("p=558,257");
        }
        router8: Router {
            @display("p=999,621");
        }
        etherSwitch: EtherSwitch {
            @display("p=250,388");
        }
        etherSwitch1: EtherSwitch {
            @display("p=319,280");
        }
        etherSwitch2: EtherSwitch {
            @display("p=455,191");
        }
        etherSwitch3: EtherSwitch {
            @display("p=579,159");
        }
        router9: Router {
            @display("p=503,744");
        }
        etherSwitch4: EtherSwitch {
            @display("p=241,541");
        }
        etherSwitch5: EtherSwitch {
            @display("p=256,653");
        }
        etherSwitch6: EtherSwitch {
            @display("p=409,801");
        }
        etherSwitch7: EtherSwitch {
            @display("p=518,839");
        }
        accessPoint: AccessPoint {
            @display("p=1005,845");
        }
        accessPoint1: AccessPoint {
            @display("p=1166,660");
        }
        DDoSBot: DDoSBot {
            @display("p=108,383");
        }
        DDoSBot1: DDoSBot {
            @display("p=146,261");
        }
        DDoSBot2: DDoSBot {
            @display("p=357,101");
        }
        standardHost: StandardHost {
            @display("p=117,320");
        }
        standardHost1: StandardHost {
            @display("p=231,166");
        }
        standardHost2: StandardHost {
            @display("p=87,507");
        }
        standardHost3: StandardHost {
            @display("p=81,568");
        }
        standardHost4: StandardHost {
            @display("p=123,746");
        }
        standardHost5: StandardHost {
            @display("p=429,62");
        }
        standardHost6: StandardHost {
            @display("p=522,37");
        }
        standardHost7: StandardHost {
            @display("p=612,26");
        }
        standardHost8: StandardHost {
            @display("p=101,686");
        }
        DDoSBot3: DDoSBot {
            @display("p=83,636");
        }
        DDoSBot4: DDoSBot {
            @display("p=181,795");
        }
        standardHost9: StandardHost {
            @display("p=271,888");
        }
        standardHost10: StandardHost {
            @display("p=372,938");
        }
        DDoSBot5: DDoSBot {
            @display("p=518,993");
        }
        wirelessHost: WirelessHost {
            @display("p=998,914");
        }
        wirelessHost1: WirelessHost {
            @display("p=1066,858");
        }
        wirelessHost2: WirelessHost {
            @display("p=1208,731");
        }
        wirelessHost3: WirelessHost {
            @display("p=1249,655");
        }
        router10: Router {
            @display("p=946,337");
        }
        splitter: Splitter {
            @display("p=596,563");
        }
        detector: Detector {
            @display("p=657,621");
        }
        splitter1: Splitter {
            @display("p=788,435");
        }
        detector1: Detector {
            @display("p=748,375");
        }
        splitter2: Splitter {
            @display("p=575,347");
        }
        splitter3: Splitter {
            @display("p=487,407");
        }
        detector2: Detector {
            @display("p=439,478");
        }
        detector3: Detector {
            @display("p=646,314");
        }
        adhocHost: AdhocHost {
            @display("p=1055,139");
        }
        accessPoint2: AccessPoint {
            @display("p=1024,290");
        }
        adhocHost1: AdhocHost {
            @display("p=1228,69");
        }
        adhocHost2: AdhocHost {
            @display("p=1306,268");
        }
        router11: Router {
            @display("p=689,513");
        }
    connections:
        DDoSBot.ethg++ <--> Eth100M <--> etherSwitch.ethg++;
        DDoSBot1.ethg++ <--> Eth100M <--> etherSwitch.ethg++;
        DDoSBot2.ethg++ <--> Eth100M <--> etherSwitch2.ethg++;
        DDoSBot3.ethg++ <--> Eth100M <--> etherSwitch4.ethg++;
        DDoSBot4.ethg++ <--> Eth100M <--> etherSwitch5.ethg++;
        DDoSBot5.ethg++ <--> Eth100M <--> etherSwitch7.ethg++;

        standardHost.ethg++ <--> Eth100M <--> etherSwitch.ethg++;
        standardHost1.ethg++ <--> Eth100M <--> etherSwitch1.ethg++;
        standardHost2.ethg++ <--> Eth100M <--> etherSwitch4.ethg++;
        standardHost3.ethg++ <--> Eth100M <--> etherSwitch4.ethg++;
        standardHost4.ethg++ <--> Eth100M <--> etherSwitch5.ethg++;
        standardHost5.ethg++ <--> Eth100M <--> etherSwitch2.ethg++;
        standardHost6.ethg++ <--> Eth100M <--> etherSwitch3.ethg++;
        standardHost7.ethg++ <--> Eth100M <--> etherSwitch3.ethg++;
        standardHost8.ethg++ <--> Eth100M <--> etherSwitch5.ethg++;
        standardHost9.ethg++ <--> Eth100M <--> etherSwitch6.ethg++;
        standardHost10.ethg++ <--> Eth100M <--> etherSwitch6.ethg++;

        etherSwitch.ethg++ <--> Eth100M <--> router4.ethg++;
        etherSwitch1.ethg++ <--> Eth100M <--> router4.ethg++;
        etherSwitch2.ethg++ <--> Eth100M <--> router7.ethg++;
        etherSwitch3.ethg++ <--> Eth100M <--> router7.ethg++;
        etherSwitch4.ethg++ <--> Eth100M <--> router6.ethg++;
        etherSwitch5.ethg++ <--> Eth100M <--> router6.ethg++;
        etherSwitch7.ethg++ <--> Eth100M <--> router9.ethg++;
        etherSwitch6.ethg++ <--> Eth100M <--> router9.ethg++;

        splitter.ethg++ <--> Eth100M <--> detector.ethg++;
        splitter1.ethg++ <--> Eth100M <--> detector1.ethg++;
        splitter2.ethg++ <--> Eth100M <--> router1.ethg++;
        splitter2.ethg++ <--> Eth100M <--> detector3.ethg++;
        splitter3.ethg++ <--> Eth100M <--> router1.ethg++;
        splitter3.ethg++ <--> Eth100M <--> detector2.ethg++;

        accessPoint.ethg++ <--> Eth100M <--> router5.ethg++;
        accessPoint1.ethg++ <--> Eth100M <--> router8.ethg++;
        accessPoint2.ethg++ <--> Eth100M <--> router10.ethg++;

        router.ethg++ <--> Eth100M <--> splitter1.ethg++;
        router3.ethg++ <--> Eth100M <--> splitter.ethg++;
        router4.ethg++ <--> Eth100M <--> splitter3.ethg++;
        router5.ethg++ <--> Eth100M <--> router2.ethg++;
        router6.ethg++ <--> Eth100M <--> router3.ethg++;
        router7.ethg++ <--> Eth100M <--> splitter2.ethg++;
        router8.ethg++ <--> Eth100M <--> router2.ethg++;
        router9.ethg++ <--> Eth100M <--> router3.ethg++;
        router10.ethg++ <--> Eth100M <--> router.ethg++;
        router11.ethg++ <--> Eth100M <--> router1.ethg++;
        router11.ethg++ <--> Eth100M <--> splitter1.ethg++;
        router11.ethg++ <--> Eth100M <--> splitter.ethg++;
        router11.ethg++ <--> Eth100M <--> router2.ethg++;
}
