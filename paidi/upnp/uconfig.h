#define UPNP_MULTICAST_IP "239.255.255.250"
#define UPNP_SERVER_PORT 1900

#define M_SEARCH "M-SEARCH * HTTP/1.1\r\n"
#define MHOST "239.255.255.250:1900\r\n"
#define DISCOVER "\"ssdp:discover\"\r\n"
#define MX_ST "MX: 5\r\nST: ssdp:all\r\n\r\n"

#define UPNP_SERVER_IP "192.168.1.34"
#define GET "GET /rootDesc.xml HTTP/1.0\r\n"
#define HOST "192.168.1.34\r\n"
#define UAGENT "Twisted PageGetter\r\n\r\n"

#define GET1 "GET /description.xml HTTP/1.0\r\n"

#define POST "POST /upnp/control/cds HTTP/1.0\r\n"
#define HOST "192.168.1.34\r\n"
#define C_LEN "438\r\n"
#define U_AGENT "Twisted PageGetter\r\n"
#define SOAPACTION "\"urn:schemas-upnp-org:service:ContentDirectory:1#Browse\"\r\n"
#define CONTENT_TYPE "text/xml ;charset=\"utf-8\"\r\n"
#define CONNECTION "close\r\n\r\n"
#define C_LEN1 "444\r\n"
#define C_LEN2 "446\r\n"
