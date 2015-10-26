//#define XMPP_SERVER_IP "10.100.33.161"
#define XMPP_SERVER_IP "192.168.1.30"
#define XMPP_SERVER_PORT 5222
#define IP_ADDR_LEN 124
#define XML_VERSION "1.0"
#define XMPP_DOMAIN_NAME_LEN 1024
#define XMPP_DOMAIN_NAME "auranetworks.in"
#define XMPP_XMLNS_NAME "jabber:client"
#define XMLNS_URL "http://etherx.jabber.org/streams"
#define XMPP_XMLNS_URL_LEN  512
#define XMPP_STREAM_STRANGA_LEN  4096
#define XMPP_XMLNS_NAME_LEN  512
#define XMLNS_STRING_ID "vr02oq09s69o6fs51gbcbnmvol65jaef1ehq4i0x"
#define XMLNS_STRING_ID_LEN 512

//#define XMPPC_USER_NAME "viasat7335"
#define XMPPC_USER_NAME "bhagavan"
#define XMPPC_UNAME_LEN 1024
#define XMPPC_PASSWORD "jnjnuh"
#define XMPPC_PSWORD_LEN 128

#define XMPPC_CNONCE "abcdefghijklmnopqrstuvwxyz"

#define MD5_DIGEST_LEN 16

#define DIGEST_URI "xmpp/auranetworks.in"
#define RESOURCE_NAME "home"
#define NC_VALUE "00000001"
#define ID "\'abcd451\'"
#define BIND_XMLNS "\'urn:ietf:params:xml:ns:xmpp-bind\'"
#define SESSION "\'urn:ietf:params:xml:ns:xmpp-session\'"
#define QUERY_XMLNS "\'http://jabber.org/protocol/disco#"
#define VCARD "\'vcard-temp\'"
#define ID1 "\'abcd452\'"
#define ID2 "\'abcd453\'"
#define QUERY "\'jabber:iq:roster\'/></iq>"
#define BLOCKLIST "\'urn:xmpp:blocking\'/></iq>"
#define PROXY "\'proxy.eu.jabber.org\'"
#define LIST_QUERY "\'http://jabber.org/protocol/bytestreams\'/></iq>"

#define PRESENCE "<status>Available</status><priority>1</priority><c xmlns='http://jabber.org/protocol/caps'/>"
//#define RECEIVE_ID "\'laptop@auranetworks.in\'"
#define RECEIVE_ID "\'paidi@auranetworks.in\'"
#define MESSAGE "&lt;cmd&gt; ADD &lt;/cmd&gt; &lt;val1&gt; 10  &lt;/val1&gt; &lt;val2&gt; \n20 &lt;val2&gt;" 
//#define MESSAGE "<cmd> ADD </cmd> <val1> 10  </val1> <val2> 20 <val2>" 
//#define MESSAGE "hello paidi" 
//#define RECEIVER_ID "\'ravi@auranetworks.in\'"
//#define MESSAG "hi ravi have u cmpltd ur lunch?"
#define MESSAGE_XMLNS "\'http://jabber.org/protocol/chatstates\'"
#define MAX_READ_SIZE 5000
#define MAX_POLL_TIMEOUT_MS 3000

int set_sock_fd(int fd);
int get_sock_fd(void);
int get_xmpp_server_ip(char *ip);
int get_xmpp_server_port(void);
int get_domain_name(char *dn);
int get_xmlns_name(char *xmlns);
int get_xmlns_url_name(char *xmlns_url);
int get_xmpp_str_id(char *xmlns_sid);
int get_user_name(char *uname);
int get_password(char *psword);
int get_cnonce(char *pcnonce);
int get_digest_uri(char *duri);
int get_resource(char *presource);
int get_nc_value(char *pnc);
int get_auth_type(void);
