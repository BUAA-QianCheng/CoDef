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
import inet._extra.linklayer.Splitter;
import inet._extra.node.Detector;
import inet.linklayer.ethernet.EtherHub;
import inet.node.ethernet.Eth100M;
import inet.node.inet.StandardHost;
import inet.node.inet.Router;
import inet._extra.node.DDoSBot;


network TestSplitter
{
    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=50,30");
        }
        visualizer: IntegratedVisualizer {
            @display("p=50,90");
        }
        standardHost: DDoSBot {
            @display("p=100,130");
        }
        standardHost1: StandardHost {
            @display("p=400,130");
        }
        router: Router {
            @display("p=300,130");
        }
        detector: Detector {
            @display("p=200,30");
        }
        splitter: Splitter {
            @display("p=200,130");
        }
    connections allowunconnected:
        standardHost.ethg++ <--> Eth100M <--> splitter.ethg++;
        splitter.ethg++ <--> Eth100M <--> router.ethg++;
        detector.ethg++ <--> Eth100M <--> splitter.ethg++;
        standardHost1.ethg++ <--> Eth100M <--> router.ethg++;
}
