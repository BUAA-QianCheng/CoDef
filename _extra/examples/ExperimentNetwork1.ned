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

network ExperimentNetwork1
{
    parameters:
        int numBot;
        int numHost;

    submodules:
        configurator: Ipv4NetworkConfigurator {
            @display("p=50,30");
        }
        visualizer: IntegratedVisualizer {
            @display("p=50,90");
        }
        bot1[numBot]: DDoSBot {
            @display("p=94,420");
        }
        bot2[numBot]: DDoSBot {
            @display("p=317,420");
        }
        bot3[numBot]: DDoSBot {
            @display("p=705,420");
        }
        bot4[numBot]: DDoSBot {
            @display("p=890,420");
        }
        host1[numHost]: StandardHost {
            @display("p=203,420");
        }
        host2[numHost]: StandardHost {
            @display("p=415,420");
        }
        host3[numHost]: StandardHost {
            @display("p=802,420");
        }
        host4[numHost]: StandardHost {
            @display("p=983,420");
        }
        connectRouter1: Router {
            @display("p=147,340");
        }
        connectRouter2: Router {
            @display("p=365,340");
        }
        connectRouter3: Router {
            @display("p=755,330");
        }
        connectRouter4: Router {
            @display("p=927,330");
        }
        detector1: Detector {
            @display("p=67,260");
        }
        detector2: Detector {
            @display("p=439,260");
        }
        detector3: Detector {
            @display("p=678,260");
        }
        detector4: Detector {
            @display("p=1009,260");
        }
        splitter2: Splitter {
            @display("p=364,260");
        }
        splitter3: Splitter {
            @display("p=756,260");
        }
        splitter4: Splitter {
            @display("p=928,260");
        }
        splitter1: Splitter {
            @display("p=148,260");
        }
        collectRouter1: Router {
            @display("p=148,180;i=abstract/opticalrouter");
        }
        collectRouter2: Router {
            @display("p=363,180;i=abstract/opticalrouter");
        }
        collectRouter3: Router {
            @display("p=757,180;i=abstract/opticalrouter");
        }
        collectRouter4: Router {
            @display("p=927,180;i=abstract/opticalrouter");
        }
        coreRouter1: Router {
            @display("p=250,100");
        }
        coreRouter2: Router {
            @display("p=841,100");
        }
        internetCloud: InternetCloud {
            @display("p=561,100;is=vl");
        }
    connections:
        for i=0..numBot-1 {
            bot1[i].ethg++ <--> Eth100M <--> connectRouter1.ethg++;
            bot2[i].ethg++ <--> Eth100M <--> connectRouter2.ethg++;
        }
        for i=0..numHost-1 {
            host1[i].ethg++ <--> Eth100M <--> connectRouter1.ethg++;
            host2[i].ethg++ <--> Eth100M <--> connectRouter2.ethg++;
        }
        for i=0..numBot-1 {
            bot3[i].ethg++ <--> Eth100M <--> connectRouter3.ethg++;
            bot4[i].ethg++ <--> Eth100M <--> connectRouter4.ethg++;
        }
        for i=0..numHost-1 {
            host3[i].ethg++ <--> Eth100M <--> connectRouter3.ethg++;
            host4[i].ethg++ <--> Eth100M <--> connectRouter4.ethg++;
        }
        coreRouter1.ethg++ <--> Eth100M <--> internetCloud.ethg++;
        coreRouter2.ethg++ <--> Eth100M <--> internetCloud.ethg++;
        collectRouter1.ethg++ <--> Eth100M <--> coreRouter1.ethg++;
        collectRouter2.ethg++ <--> Eth100M <--> coreRouter1.ethg++;
        collectRouter3.ethg++ <--> Eth100M <--> coreRouter2.ethg++;
        collectRouter4.ethg++ <--> Eth100M <--> coreRouter2.ethg++;
        connectRouter1.ethg++ <--> Eth100M <--> splitter1.ethg++;
        connectRouter2.ethg++ <--> Eth100M <--> splitter2.ethg++;
        connectRouter3.ethg++ <--> Eth100M <--> splitter3.ethg++;
        connectRouter4.ethg++ <--> Eth100M <--> splitter4.ethg++;
        splitter1.ethg++ <--> Eth100M <--> detector1.ethg++;
        splitter2.ethg++ <--> Eth100M <--> detector2.ethg++;
        splitter3.ethg++ <--> Eth100M <--> detector3.ethg++;
        splitter4.ethg++ <--> Eth100M <--> detector4.ethg++;
        splitter1.ethg++ <--> Eth100M <--> collectRouter1.ethg++;
        splitter2.ethg++ <--> Eth100M <--> collectRouter2.ethg++;
        splitter3.ethg++ <--> Eth100M <--> collectRouter3.ethg++;
        splitter4.ethg++ <--> Eth100M <--> collectRouter4.ethg++;
}
