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

import inet.common.INETDefs;
import inet.common.packet.chunk.Chunk;

namespace inet;

enum RequestType {
	GET = 1; 
	POST = 2;
	PUT = 3;
	DEL = 4;
}

enum ResponseType {
	//Success 2.xx
	CREATED = 201;
	DELETED = 202;
	VALID = 203;
	CHANGED = 204;
	CONTENT = 205;
	///Client Error 4.xx
	BAD_REQUEST = 400;
	UNAUTHORIZED = 401;
	BAD_OPTION = 402;
	FORBIDDEN = 403;
	NOT_FOUND = 404;
	METHOD_NOT_ALLOWED = 405;
	NOT_ACCEPTABLE = 406;
	CONFLICT = 409;
	PRECONDITION_FAILED = 412;
	REQUEST_ENTITY_TOO_LARGE = 413;
	UNSUPPORTED_CONTENT_FORMAT = 415;
	//Server Error 5.xx
	INTERNAL_SERVER_ERROR = 500;
	NOT_IMPLEMENTED = 501;
	BAD_GATEWAY = 502;
	SERVICE_UNAVAILABLE = 503;
	GATEWAY_TIMEOUT = 504;
	PROXYING_NOT_SUPPORTED = 505;
}

class CoDefRequestHeader extends FieldsChunk{
	RequestType header;
	string uriPath[];
}

class CoDefResponseHeader extends FieldsChunk{ 
	ResponseType header;
	string uriPath[];
}







