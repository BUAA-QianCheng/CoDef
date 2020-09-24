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

package inet._extra.applications.codefagent;

import inet.applications.contract.IApp;

simple CoDefClient like IApp{
    parameters:
        string serverAddr = default("");
        
        double startTime @unit(s) = default(uniform(0s, this.sleepDuration + this.sendInterval)); // send first ping at startTime
        double stopTime @unit(s) = default(-1s); // time to finish sending, negative values mean forever
        
    gates:
	    input socketIn;
        output socketOut;
}