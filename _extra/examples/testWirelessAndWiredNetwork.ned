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
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;
import inet.visualizer.integrated.IntegratedVisualizer;

import inet.node.inet.WirelessHost;
import inet.node.wireless.AccessPoint;
import inet.node.inet.StandardHost;
import inet.node.inet.Router;
import inet.node.ethernet.EtherSwitch;
import inet.node.ethernet.Eth100M;

network TestWirelessAndWiredNetwork
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
        etherSwitch: EtherSwitch {
            @display("p=430,125");
        }
        router: Router {
            @display("p=340,125");
        }
        wirelessHost1: WirelessHost {
            @display("p=150,70");
        }
        accessPoint: AccessPoint {
            @display("p=250,125");
        }
        standardHost1: StandardHost {
            @display("p=520,70");
        }
        standardHost2: StandardHost {
            @display("p=520,180");
        }
        wirelessHost2: WirelessHost {
            @display("p=150,180");
        }
    connections:
        accessPoint.ethg++ <--> Eth100M <--> router.ethg++;
        etherSwitch.ethg++ <--> Eth100M <--> router.ethg++;
        standardHost1.ethg++ <--> Eth100M <--> etherSwitch.ethg++;
        standardHost2.ethg++ <--> Eth100M <--> etherSwitch.ethg++;
}
