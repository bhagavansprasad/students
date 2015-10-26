
#include <stdio.h>
#include "xmppc.h"
#include "config.h"
#include <string.h>
#include "base64_utils.h"
#include "utils.h"
#include <openssl/md5.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>


//GLOBAL VARIABLES
xmpp_context_block xmpp_cb;
int g_xmppc_state = XMPPC_INIT_STATE;

int set_state_to(int new_state)
{
	int old_state = g_xmppc_state;
	//XMPP_DEBUG("-->%d, %s, %s, state :%d\n", __LINE__, __FUNCTION__, __FILE__, new_state);

	g_xmppc_state = new_state;

	return old_state;
}

struct pollfd pfds[10];
int tot_fds = 0;

int set_pol_fds(int fd)
{
	pfds[tot_fds].fd = fd;
	pfds[tot_fds].events = POLLIN;

	tot_fds++;

	printf("-->total polling fds :%d\n", tot_fds);

	return tot_fds;
}

int xmppc_init_client()
{
	int connected;
	int state = 0;
	int socketfd;
	struct sockaddr_in myclientaddr;
	char srvr_ip[IP_ADDR_LEN];

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	get_user_name(xmpp_cb.username);
	get_password(xmpp_cb.password);

	socketfd= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(socketfd == -1)
	{
		perror("Failed to create a socket \r\n");
		exit(1);
	}

	myclientaddr.sin_family = AF_INET;

	get_xmpp_server_ip(srvr_ip);
	myclientaddr.sin_addr.s_addr = inet_addr(srvr_ip);
	myclientaddr.sin_port = htons(get_xmpp_server_port());

	XMPP_DEBUG("-->client : Connecting to the server\r\n");
	connected = connect(socketfd, (struct sockaddr *)&myclientaddr, sizeof(myclientaddr));
	if(connected == -1)
	{
		perror("connect system call failed\r\n");
		exit(1);
	}

	XMPP_DEBUG("-->Connected to server retval :%d\n", connected);
	set_sock_fd(socketfd);
	set_pol_fds(socketfd);

	state = XMPPC_SEND_VERSION_STATE;

	set_state_to(state);

	return 0;
}


int xmppc_send_version()
{
	char buff[512];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	sprintf(buff, "<?xml version='%s' ?>", XML_VERSION);
	XMPP_DEBUG("-->C2S: first string :%s\n", buff);

	xmpp_write_to_server(buff, strlen(buff));

	state = XMPPC_SEND_STREAM_STATE;

	set_state_to(state);

	return 0;
}

int xmppc_send_stream(int fd)
{
	char domain_name[XMPP_DOMAIN_NAME_LEN];
	char buff[XMPP_STREAM_STRANGA_LEN];
	char xmlns_name[XMPP_XMLNS_NAME_LEN];
	char xmlns_url_name[XMPP_XMLNS_URL_LEN];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	get_domain_name(domain_name);
	get_xmlns_name(xmlns_name);
	get_xmlns_url_name(xmlns_url_name);

	sprintf(buff, "<stream:stream to='%s' xmlns='%s' xmlns:stream='%s' version='%s'>",
			XMPP_DOMAIN_NAME, XMPP_XMLNS_NAME, XMLNS_URL, XML_VERSION );

	xmpp_write_to_server(buff, strlen(buff));

	state = XMPPC_RECV_STREAM_ID_STATE;

	set_state_to(state);

	return 0;
}

int parse_auth_mechanisam(char *auth_offer_stanza)
{
	char mech_1[100], mech_2[100], *str_id = NULL;
	int j=0, k=0;

	str_id = strstr(auth_offer_stanza, "<mechanism>");
	if (str_id == NULL)
	{
		XMPP_DEBUG("-->Waiting from mechanisam offer, but not received\n");
		return (XMPPC_EXIT_STATE);
	}

	//TODO: What if MD5 is recived first and then PLAIN????
	XMPP_DEBUG("-->Mechanisam offered :%s\n", str_id);
	for( ; *str_id  !=  '>' ; str_id++);

	str_id++;

	for (j = 0; *str_id != '<' && *str_id; str_id++, j++)
		mech_1[j] = *str_id;

	mech_1[j] = '\0';
	XMPP_DEBUG("-->received mechanisam :%s\n", mech_1); 

	if(strcmp(mech_1, "PLAIN") == 0)
	{
		xmpp_cb.auth_offer[0]=1;
	}

	char *str_id1 = strstr(auth_offer_stanza, "</mechanism>");
	for( ; *str_id1 !=  '>' ; str_id1++);
	for( ; *str_id1++ !=  '>' ; str_id1++);
	for( ; *str_id1 !=  '>' ; str_id1++);
	while((*(++str_id1)) != '<' )
	{
		mech_2[k] = *str_id1;
		k++;
	}
	mech_2[k] = '\0';
	XMPP_DEBUG("-->received mechanisam :%s\n", mech_2); 
	if(strcmp(mech_2, "DIGEST-MD5") == 0)
		xmpp_cb.auth_offer[1]=2;

	return 0;
}

int xmppc_recv_streamid()
{
	int j=0;
	char recv_buffer[XMPP_STREAM_STRANGA_LEN];
	int retval = 0;
	char *str_id = NULL;
	char get_id[XMPP_ID_LEN];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	//TODO: move all parsing related activities to utils file
	retval = xmpp_read_from_server(recv_buffer, sizeof(recv_buffer));

	str_id = strstr(recv_buffer, "id");

	//Incase of id is not received
	if (str_id == NULL)
	{
		XMPP_DEBUG("-->Waiting for id but not received\n");
		state = XMPPC_EXIT_STATE;
		goto lbl_exit;
	}
	XMPP_DEBUG("-->%p\n", str_id);

	for( ; *str_id !=  '\'' && *str_id; str_id++);

	for(j = 0; (*(++str_id)) != '\'' && j < retval; j++)
		get_id[j] = *str_id;

	get_id[++j] = '\0';

	XMPP_DEBUG("-->recevied id :%s\n", get_id); 

	//Incase of Authentication Mechanisam is also received in the same packet
	if (strstr(recv_buffer, "<mechanism>") != NULL)
	{
		if ((state = parse_auth_mechanisam(recv_buffer)) == XMPPC_EXIT_STATE)
			goto lbl_exit;

		state = XMPPC_AUTH_SELECT_STATE;
		goto lbl_exit;
	}

	state = XMPPC_AUTH_OFFER_RECV_STATE;

lbl_exit:
	set_state_to(state);
	return 0;
}

int xmppc_auth_offer_recv(char *buff)
{
	char auth_offer_stanza[XMPP_STREAM_STRANGA_LEN];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	xmpp_read_from_server(auth_offer_stanza, sizeof(auth_offer_stanza));

	if ((state = parse_auth_mechanisam(auth_offer_stanza)) == XMPPC_EXIT_STATE)
		goto lbl_exit;

	state = XMPPC_AUTH_SELECT_STATE;
	goto lbl_exit;

lbl_exit:
	set_state_to(state);
	return 0;
}

int xmppc_auth_select(char *buff)
{
	int state = 0;
	//int auth_mechnisam = AUTHENTICATION_MD5;
	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

#if 0
	if(xmpp_cb.auth_offer[0] == 1)
		set_state_to(XMPPC_PLAIN_AUTH_STATE);
#endif

	state = XMPPC_MD5_AUTH_STATE;

	set_state_to(state);

	return 0;
}


int xmppc_do_plain_auth(int fd)
{
	int state = 0;
	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	state = XMPPC_RECV_CHALLENGE_STATE;

	set_state_to(state);

#if 0

	if it is plain mechanism put the valves into the structure as
		username,password

			build authentication string with plain text,and decode with base64
			mechanism and
			send authentication plain text,
#endif
	return 0;
}


int xmppc_do_md5_auth(int fd)
{
	char buff[1024] = "";
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	sprintf(buff, "<auth xmlns='urn:ietf:params:xml:ns:xmpp-sasl' mechanism='%s'></auth>", 
		(get_auth_type() == AUTH_DIGEST_MD5 ? "DIGEST-MD5" : "PLAIN"));

	xmpp_write_to_server(buff, strlen(buff));

	state = XMPPC_RECV_CHALLENGE_STATE;

	set_state_to(state);

	return 0;
}


int xmppc_recv_challenge(char *buff)
{
	char tbuff[1024];
	int retval= 0;
	int i=0;
	char *decode_str = NULL;
	int decode_len = 0;
	char challange[256];
	int challange_len = 0;
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	xmpp_read_from_server(tbuff, sizeof(tbuff));

	//TODO: What if the string is not 'CHALLENGE???'

	parse_challange(tbuff, retval, challange, &challange_len);

	XMPP_DEBUG("-->received challenge :");
	for (i = 0; i < challange_len; i++)
		XMPP_DEBUG("%c", challange[i]);

	XMPP_DEBUG("\n");
	decode_str = base64_decode(challange, challange_len, (size_t *)&decode_len);

	parse_realm(decode_str, xmpp_cb.realm);
	XMPP_DEBUG("-->realm :%s\n", xmpp_cb.realm);

	xmpp_cb.nonce_len = parse_nonce(decode_str, xmpp_cb.nonce);
	XMPP_DEBUG("-->nonce :%s, len :%d\n", xmpp_cb.nonce, xmpp_cb.nonce_len);

	parse_qop(decode_str, xmpp_cb.qop);
	XMPP_DEBUG("-->qop :%s\n", xmpp_cb.qop);

	parse_charset(decode_str, xmpp_cb.charset);
	XMPP_DEBUG("-->charset :%s\n", xmpp_cb.charset);

	state = XMPPC_SEND_CREDENTIAL_STATE;

	set_state_to(state);

	return 0;
}


#if 0
1. Create a string of the form "username:realm:password". Call this string X.
2. Compute the 16 octet MD5 hash of X. Call the result Y.
3. Create a string of the form "Y:nonce:cnonce:authzid". Call this string A1.
4. Create a string of the form "AUTHENTICATE:digest-uri". Call this string A2.
5. Compute the 32 hex digit MD5 hash of A1. Call the result HA1.
6. Compute the 32 hex digit MD5 hash of A2. Call the result HA2.
7. Create a string of the form "HA1:nonce:nc:cnonce:qop:HA2". Call this string KD.
8. Compute the 32 hex digit MD5 hash of KD. Call the result Z.
#endif
static int generate_response_value(unsigned char *resp, char *jid, const char *passwd,
	const char *nonce, const char *cnonce, const char *a2, const char *realm)
{
	int i = 0;
	char x[1024] = "";
	char a1[512] = "";
	unsigned char ha1[512] = "";
	unsigned char ha2[512] = "";
	char *eha1 = NULL;
	char *eha2 = NULL;
	unsigned char hkd[512] = "";
	char *ehkd = NULL;
	unsigned char y[128] = "";
	char kd[512] = "";

	XMPP_DEBUG("\n\n-->jid :%s, password :%s, nonce :%s, cnonce :%s, a2 :%s, realm :%s\n", jid, passwd, nonce, cnonce, a2, realm);

	sprintf(x, "%s:%s:%s", jid, realm, passwd);
	XMPP_DEBUG("-->x >> jid:realm:passwd\n");
	XMPP_DEBUG("-->x >> :%s\n", x);

	MD5((const unsigned char *)x, strlen(x), y);
	XMPP_DEBUG("-->MD5(x) i.e. y :");
	for (i = 0; i < 16; i++)
		XMPP_DEBUG("%02x", y[i]);
	XMPP_DEBUG("\n");

	sprintf(a1, "xxxxxxxxxxxxxxxx:%s:%s", nonce, cnonce);
	memmove(a1, y, 16);

	XMPP_DEBUG("-->a1 >> y:nonce:cnonce");
	for (i = 0; i < 16; i++)
		XMPP_DEBUG("%02x", a1[i]);
	XMPP_DEBUG("%s", a1+16);
	XMPP_DEBUG("\n");

	MD5((const unsigned char *)a1, strlen(a1), ha1);
	XMPP_DEBUG("-->MD5(a1) i.e. before base16 ha1 :");
	for (i = 0; i < 16; i++)
		XMPP_DEBUG("%02x", ha1[i]);
	XMPP_DEBUG("\n");

	eha1 = base16_encode((char *)ha1, 16);
	XMPP_DEBUG("-->MD5(a1) i.e.  after base16 ha1 :");
	for (i = 0; i < strlen(eha1); i++)
		XMPP_DEBUG("%02x", eha1[i]);
	XMPP_DEBUG("\n");

	XMPP_DEBUG("-->a2 :%s\n" , a2);
	MD5((const unsigned char *)a2, strlen(a2), ha2);
	XMPP_DEBUG("-->MD5(a2), i.e. before base16, HA2 :");
	for (i = 0; i < 16; i++)
		XMPP_DEBUG("%02x", ha2[i]);
	XMPP_DEBUG("\n");

	eha2 = base16_encode((char *)ha2, 16);
	XMPP_DEBUG("-->MD5(a2), i.e.  after base16, HA2 :");
	for (i = 0; i < strlen(eha2); i++)
		XMPP_DEBUG("%02x", eha2[i]);
	XMPP_DEBUG("\n");

	XMPP_DEBUG("-->eha2 :%s\n", eha2);

	sprintf(kd, "%s:%s:00000001:%s:auth:%s", eha1, nonce, cnonce, eha2);
	XMPP_DEBUG("-->kd len :%d, kd:%s\n", (int)strlen(kd), kd);

	MD5((const unsigned char *)kd, strlen(kd), hkd);
	XMPP_DEBUG("-->%d: MD5(kd) i.e. z, before base16 :", __LINE__);
	for (i = 0; i < 16; i++)
		XMPP_DEBUG("%02x", hkd[i]);
	XMPP_DEBUG("\n");

	ehkd = base16_encode((char *)hkd, 16);
	XMPP_DEBUG("-->%d: MD5(kd) i.e. z, after  base16 :", __LINE__);
	for (i = 0; i < strlen(ehkd); i++)
		XMPP_DEBUG("%02x", ehkd[i]);
	XMPP_DEBUG("\n");

	memcpy(resp, ehkd, strlen(ehkd)+1);

	return 0;
}
#if 0
int test_xmpp_cb_fill_new_values(xmpp_context_block *pcb)
{
	strcpy(pcb->username, "bhagavanp");
	strcpy(pcb->password, "jnjnuh");
	strcpy(pcb->nonce, "MPJxwLuiPJwCnlWgxVe/Qg==");
	strcpy(pcb->cnonce, "anmnzS4ZmwfC+0DmR7oUiqRekxCpOGbM+PaSyw2lLAw=");
	strcpy(pcb->a2, "AUTHENTICATE:xmpp/auranetworks.in");
	strcpy(pcb->realm, "auranetworks.in");

	return 0;
}
#endif
int xmpp_send_credentials(int fd)
{
	int encoded_len = 0;
	char cnonce[1024] = "";
	unsigned char base16_z[1024] = "";
	char digest_uri[1024] = "";
	char a2[512] = "";
	char resource[1024] = "";
	char resp[2048] = "";
	char *encoded_resp;
	char cdata[1024] = "";
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	get_cnonce(cnonce);
	get_digest_uri(digest_uri);
	get_resource(resource);

	sprintf(a2, "%s:%s", "AUTHENTICATE", digest_uri);
	XMPP_DEBUG("-->a2 >>AUTHENTICATE:digest-uri\n");
	XMPP_DEBUG("-->a2 >>%s\n", a2);

	//test_xmpp_cb_fill_new_values(&xmpp_cb);

	generate_response_value(base16_z, xmpp_cb.username, xmpp_cb.password, xmpp_cb.nonce, cnonce, a2, xmpp_cb.realm);

	sprintf(resp,
		"username=\"%s\",realm=\"%s\",nonce=\"%s\",cnonce=\"%s\",nc=00000001,qop=%s,digest-uri=\"%s\",response=%s,charset=%s",
		xmpp_cb.username, xmpp_cb.realm, xmpp_cb.nonce, cnonce, xmpp_cb.qop,
		digest_uri, base16_z, xmpp_cb.charset); 

	XMPP_DEBUG("-->resp len :%d, resp :%s\n", (int)strlen(resp), resp);

	encoded_resp = base64_encode((const char *)resp, strlen(resp), (size_t *)&encoded_len);
	encoded_resp[encoded_len] = '\0';
	XMPP_DEBUG("-->encoded response :%s\n, len :%d\n", encoded_resp, encoded_len);

	sprintf(cdata, "<response xmlns='urn:ietf:params:xml:ns:xmpp-sasl'>%s</response>", encoded_resp);
	XMPP_DEBUG("-->cdata len :%d cdata :%s\n", (int)strlen(cdata), cdata);

	xmpp_write_to_server(cdata, strlen(cdata)); 

	state = XMPPC_AUTH_STATUS_STATE;

	set_state_to(state);

	return 0;
}

int xmpp_recv_auth_status(void)
{
	char tbuff[1024];
	int state = 0;
	char *str_id = NULL;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	xmpp_read_from_server(tbuff, sizeof(tbuff));

	if ((str_id = strstr(tbuff, "failure")) != NULL)
	{
		XMPP_DEBUG("-->Authentication failure\n");
		state = XMPPC_EXIT_STATE;
	}
	else if ((str_id = strstr(tbuff, "challenge")) != NULL)
	{
		XMPP_DEBUG("-->Received Challenge for second time\n");
		state = XMPP_SEND_EMPTY_RESPONSE; 
	}
	else if ((str_id = strstr(tbuff, "success")) != NULL)
	{
		XMPP_DEBUG("-->Authentication successful\n");
		state = XMPP_SEND_EMPTY_RESPONSE; 
	}

	set_state_to(state);

	return 0;
}

int xmpp_send_empty_response(void)
{
	int state = 0;
	char resp[1024] = "";

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	sprintf(resp, "<stream:stream to='%s' xmlns='jabber:client' xmlns:stream='http://etherx.jabber.org/streams' version='%s'>",
		xmpp_cb.realm, XML_VERSION);

	XMPP_DEBUG("-->resp len :%d, resp :%s\n", (int)strlen(resp), resp);

	xmpp_write_to_server(resp, strlen(resp));

	state = XMPPC_RECV_ID_STATE;

	set_state_to(state);

	return 0;
}

#if 0
int xmpp_recv_success(void)
{
	char tbuff[1024];
	int state = 0;

	printf("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(tbuff, sizeof(tbuff));

	state = XMPPC_SEND_AGAIN_STREAM_STATE;

	set_state_to(state);

	return 0;
}
#endif

#if 0
int xmpp_recv_session_id(void)
{
	char tbuff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	xmpp_read_from_server(tbuff, sizeof(tbuff));

	//state = XMPPC_SEND_STREAMS_STATE; 
	state = XMPPC_RECV_FEATURE_STATE; 

	set_state_to(state);

	return 0;
}
#endif

int xmppc_send_second_time_stream(void)
{
	int state = 0;
	char resp[1024] = "";

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	sprintf(resp, "<stream:stream to='%s' xmlns='jabber:client' xmlns:stream='http://etherx.jabber.org/streams' version='%s'>", xmpp_cb.realm, XML_VERSION);

	xmpp_write_to_server(resp, strlen(resp));
	state = XMPPC_RECV_ID_STATE;

	set_state_to(state);

	return 0;
}

int xmppc_recv_second_id(void)
{
	char tbuff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(tbuff, sizeof(tbuff));
	state = XMPPC_RECV_STREAM_FEATURES_STATE; 
	set_state_to(state); 

	return 0;
}

#if 0
int xmppc_send_streams(void)
{
	int state = 0;
	char resp[1024] = "";

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	sprintf(resp, "<stream:stream to='%s' xmlns='jabber:client' xmlns:stream='http://etherx.jabber.org/streams' version='%s'>",
			xmpp_cb.realm, XML_VERSION);

	XMPP_DEBUG("-->resp len :%d, resp :%s\n", strlen(resp), resp);

	xmpp_write_to_server(resp, strlen(resp));

	state = XMPPC_RECV_FEATURE_STATE;

	set_state_to(state);

	return 0;
}
#endif

#if 0
int xmppc_recv_session_id(void)
{
	char tbuff[1024];
	int state = 0;

	XMPP_DEBUG("-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(tbuff, sizeof(tbuff));

	state = XMPPC_RECV_FEATURE_STATE; 

	set_state_to(state); 

	return 0;
}
#endif

int  xmppc_recv_stream_features(void)
{
	char sbuff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(sbuff, sizeof(sbuff));

	state = XMPPC_SEND_ID_RESOURCE_STATE;

	set_state_to(state);

	return 0;
}

int xmppc_send_id_resource(void)
{
	char sbuff[1024];
	char buff[1024]="<resource>home</resource></bind></iq>";
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	sprintf(sbuff,"<iq type=\'set\' id=%s><bind xmlns=%s>%s", ID, BIND_XMLNS, buff);

	xmpp_write_to_server(sbuff, strlen(sbuff));

	state = XMPPC_RECV_JID_STATE;

	set_state_to(state);

	return 0;

}

int xmppc_recv_jid(void)
{
	char buff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(buff, sizeof(buff));

	state = XMPPC_SEND_SESSION_STATE;

	set_state_to(state);

	return 0;
}

int xmppc_send_session(void)
{
	char sbuff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	sprintf(sbuff,"<iq type='set' id=%s><session xmlns=%s/></iq>", ID, SESSION);

	xmpp_write_to_server(sbuff, strlen(sbuff));

	state = XMPPC_RECV_SESSION_STATE;

	set_state_to(state);

	return 0;

}

int xmppc_recv_session(void)
{
	char buff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(buff, sizeof(buff));

	state = XMPPC_SEND_QUERY_ITEMS_STATE;	

	set_state_to(state);

	return 0;
}

int xmppc_send_query(void)
{
	char sbuff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	sprintf(sbuff,"<iq type='get' id=%s to=\'%s\'><query xmlns=%sitems\'/></iq>",ID,XMPP_DOMAIN_NAME,QUERY_XMLNS);

	xmpp_write_to_server(sbuff, strlen(sbuff));

	state = XMPPC_RECV_QUERY_ITEMS_STATE;

	set_state_to(state);

	return 0;

}

int  xmppc_recv_query(void)
{
	char buff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(buff, sizeof(buff));

	state = XMPPC_SEND_QUERY_INFO_STATE;	

	set_state_to(state);

	return 0;

}
int xmppc_send_query_info(void)
{
	char sbuff[2024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	sprintf(sbuff,"<iq type='get' id=%s to =\'%s\'><query xmlns=%sinfo\'/></iq>",ID,XMPP_DOMAIN_NAME, QUERY_XMLNS);

	xmpp_write_to_server(sbuff, strlen(sbuff));

	state = XMPPC_RECV_QUERY_INFO_STATE;

	set_state_to(state);

	return 0;
}

int  xmppc_recv_query_info(void)
{
	char buff[1500];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(buff, sizeof(buff));

	state = XMPPC_SEND_VCARD_STATE;	

	set_state_to(state);

	return 0;
}

int xmppc_send_vcard(void)
{
	char sbuff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	sprintf(sbuff,"<iq type='get' id=%s><vCard xmlns=%s/></iq>", ID, VCARD);

	xmpp_write_to_server(sbuff, strlen(sbuff));

	state = XMPPC_RECV_VCARD_STATE;

	set_state_to(state);

	return 0;
}

int xmppc_recv_vcard(void)
{
	char rvcard[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(rvcard, sizeof(rvcard));

	state = XMPPC_SEND_LIST_STATE;

	set_state_to(state);
	return 0;
}

int xmppc_send_list(void)
{
	char sbuff[1024];
	int state = 0;
	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	sprintf(sbuff,"<iq type='get' id=%s><query xmlns=%s<iq type='get' id=%s><blocklist xmlns=%s<iq type='get' id=%s to=%s><query xmlns=%s",ID , QUERY, ID1, BLOCKLIST, ID2, PROXY, LIST_QUERY); 

	xmpp_write_to_server(sbuff, strlen(sbuff));

	state = XMPPC_RECV_LIST_STATE;

	set_state_to(state);

	return 0;

}

int  xmppc_recv_list(void)
{
	char list[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(list, sizeof(list));

	state = XMPPC_SEND_PRESENCE_STATE;

	state = set_state_to(state);

	return 0;

}


int xmppc_send_message_to_buddy(char *preply)
{
	char buff[5048] = "";
	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	sprintf(buff, "<presence>%s</presence>", PRESENCE);
	xmpp_write_to_server(buff, strlen(buff));

	sprintf(buff, "<message type='chat' id=%s to=%s><composing xmlns=%s/></message>", ID, RECEIVE_ID, MESSAGE_XMLNS);
	xmpp_write_to_server(buff, strlen(buff));

	//msg = xcatalog_populate_planner(buff);
	printf("-->len :%d, message :%s\n", (int)strlen(preply), preply);
	sprintf(buff, "<message type='chat' id=%s to=%s><composing xmlns=%s/><body>%s</body></message>", ID, RECEIVE_ID, MESSAGE_XMLNS, preply);
	//sprintf(buff, "<message type='chat' id=%s to=%s><composing xmlns=%s/><body>%s</body></message>", ID, RECEIVE_ID, MESSAGE_XMLNS, MESSAGE);
	xmpp_write_to_server(buff, strlen(buff));

	sprintf(buff,"<message type='chat' id=%s to=%s><active xmlns=%s/></message>", ID, RECEIVE_ID, MESSAGE_XMLNS);
	xmpp_write_to_server(buff, strlen(buff));

	return 0;
}

//get 10
//del 389
//ren 39 40
int parse_arguments(char *cmd, int *arg1, int *arg2)
{
	int i = 0;

	printf("-->%d, i :%d\n", __LINE__, i);
	for(i = 0; cmd[i] && cmd[i] == ' '; i++); //skip leading spaces
	for(     ; cmd[i] && cmd[i] != ' '; i++); //skip command
	for(     ; cmd[i] && cmd[i] == ' '; i++);//skip spaces before arg1
	for(     ; cmd[i] && cmd[i] != ' '; i++) //Convert arg1 to int
		*arg1 = (*arg1 * 10) + cmd[i] - '0';
		
	for(     ; cmd[i] && cmd[i] == ' '; i++);//skip spaces after arg1, before arg2
	for(     ; cmd[i] && cmd[i] != ' '; i++) //Convert arg2 to int
		*arg2 = (*arg2 * 10) + cmd[i] - '0';

	return 0;
}

int parse_arguments_int_str(char *cmd, int *arg1, char *nname)
{
	int i = 0, j = 0;

	printf("-->%d, i :%d\n", __LINE__, i);
	for(i = 0; cmd[i] && cmd[i] == ' '; i++); //skip leading spaces
	for(     ; cmd[i] && cmd[i] != ' '; i++); //skip command
	for(     ; cmd[i] && cmd[i] == ' '; i++);//skip spaces before arg1
	for(     ; cmd[i] && cmd[i] != ' '; i++) //Convert arg1 to int
		*arg1 = (*arg1 * 10) + cmd[i] - '0';
		
	for(     ; cmd[i] && cmd[i] == ' '; i++);//skip spaces after arg1, before arg2
	for(j = 0; (nname[j] = cmd[i]); i++, j++); //store arg2 i.e. name to nname

	return 0;
}

int xcatalog_populate_planner(char *preply, int *prlen, int count);
int delete_catalog_event_by_index(char *preply, int *prlen, int index);
int rename_prog_channel_number_by_index(char *preply, int *prlen, int index, int new_number);
int rename_prog_name_by_index(char *preply, int *prlen, int index, char *nname);
int xmpp_record_live(char *preply, int *prlen, int channel);

int handle_command(char *cmd, char *preply, int *prlen)
{
	int arg1, arg2;
	char nname[1024];

	arg1 = arg2 = 0;

	XMPP_DEBUG("-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	if(strncasecmp("get", cmd, 3) == 0)
	{
		parse_arguments(cmd, &arg1, &arg2);
		printf("-->arg1 :%d, arg2 :%d\n", arg1, arg2);
		return xcatalog_populate_planner(preply, prlen, arg1);
	}
	else if (strncasecmp("del", cmd, 3) == 0)
	{
		parse_arguments(cmd, &arg1, &arg2);
		printf("-->arg1 :%d, arg2 :%d\n", arg1, arg2);
		return delete_catalog_event_by_index(preply, prlen, arg1-1);
	}
	else if (strncasecmp("mvcn", cmd, 4) == 0)
	{
		parse_arguments(cmd, &arg1, &arg2);
		printf("-->arg1 :%d, arg2 :%d\n", arg1, arg2);
		return rename_prog_channel_number_by_index(preply, prlen, arg1-1, arg2);
	}
	else if (strncasecmp("mvpn", cmd, 4) == 0)
	{
		parse_arguments_int_str(cmd, &arg1, nname);
		printf("-->arg1 :%d, name :%s\n", arg1, nname);
		return rename_prog_name_by_index(preply, prlen, arg1-1, nname);
	}
	else if (strncasecmp("bookl", cmd, 5) == 0)
	{
		XMPP_DEBUG("-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
		return xmpp_record_live(preply, prlen, 3);
	}
	else if (strncasecmp("crash", cmd, 5) == 0)
	{
		arg1 = 10/arg2;
	}

	printf("-->INVALID COMMAND\n");
	*prlen = sprintf(preply, "Invalid/Unsupported command");

	return 0;
}

int parse_body(char *msg, char *preply, int *prlen)
{
	int i = 0;
	char *temp = NULL;

	msg++;

	for(i = 0; msg[i] != '>' && msg[i] != '\0'; i++);
	temp = (msg+i+1);
	for(     ; msg[i] != '<' && msg[i] != '\0'; i++);

	msg[i] = '\0';

	printf("-->Command received :%s\n", temp);

	return handle_command(temp, preply, prlen);
}

#if 0
int xmppc_recv_message_from_buddy(void)
{
	char buff[1024];
	char *ptr = NULL;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);

	xmpp_read_from_server(buff, sizeof(buff));
	if ((ptr = strstr(buff, "<body>")) != NULL)
		parse_body(ptr);

	xmpp_read_from_server(buff, sizeof(buff));
	if ((ptr = strstr(buff, "<body>")) != NULL)
		parse_body(ptr);

	xmpp_read_from_server(buff, sizeof(buff));
	if ((ptr = strstr(buff, "<body>")) != NULL)
		parse_body(ptr);

	xmpp_read_from_server(buff, sizeof(buff));
	if ((ptr = strstr(buff, "<body>")) != NULL)
		parse_body(ptr);

	return 0;
}
#endif

int xmppc_poll_for_messages(int fd_count, char *preply, int *prlen)
{
	int ret = 0;
	int retval  = 0, i = 0;
	char buf[MAX_READ_SIZE], *ptr = NULL;

	//ret = poll(pfds, tot_fds, MAX_POLL_TIMEOUT_MS);
	ret = poll(pfds, tot_fds, -1);

	printf("-->xmppc: poll retval :%d\n", ret);

	if (ret <= 0)
		return 0;
		//check_fds(pfds, tot_fds, reply, rlen);

	if (pfds[0].revents & POLLIN)  //pipe fd
	{
		retval = read(pfds[0].fd, buf, MAX_READ_SIZE);
		buf[retval] = '\0';
		printf("-->PIPE, received data len :%d, received message :%s\n", retval, buf);
	}

	for (i = 1; i < tot_fds; i++)
	{
		retval = read(pfds[i].fd, buf, MAX_READ_SIZE);
		buf[retval] = '\0';
		printf("-->SOCKET, received data len :%d\n", retval);

		if ((ptr = strstr(buf, "<body>")) != NULL)
			parse_body(ptr, preply, prlen);
	}

	return 0;
}

int xmppc_msg_send_n_recv(void)
{
	int state = 0;
	char reply[MAX_READ_SIZE] = " ";;
	int rep_len = -1;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmppc_poll_for_messages(tot_fds, reply, &rep_len);
	if (rep_len > 0)
		xmppc_send_message_to_buddy(reply);

	state = XMPPC_SEND_AND_RECV_MESSAGES_STATE;
	set_state_to(state);

	return 0;
}

int xmppc_send_presence(void)
{
	char sbuff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	sprintf(sbuff,"<presence>%s</presence>",PRESENCE);
	xmpp_write_to_server(sbuff, strlen(sbuff));

	state = XMPPC_RECV_PRESENCE_STATE;

	set_state_to(state);

	return 0;
}

int xmppc_recv_presence(void)
{
	char buff[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(buff, sizeof(buff));

	//signal(SIGINT,sendmesg);
	//for(;;);

	state = XMPPC_SEND_AND_RECV_MESSAGES_STATE;
	set_state_to(state);

	return 0;
}

int xmppc_send_composing(void)
{
	char composing[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	sprintf(composing,"<message type='chat' id=%s to=%s><composing xmlns=%s/></message>", ID, RECEIVE_ID,MESSAGE_XMLNS);

	xmpp_write_to_server(composing, strlen(composing));

	state = XMPPC_RECV_COMPOSING_STATE;
	set_state_to(state);

	return 0;
}

#if 0
	XMPP_DEBUG("-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(buff, sizeof(buff));

	sprintf(active,"<message type='chat' id=%s to=%s><active xmlns=%s/></message>", ID, RECEIVE_ID,MESSAGE_XMLNS);

	xmpp_write_to_server(active, strlen(active));

	xmpp_read_from_server(buff, sizeof(buff));

	// set_state_to(XMPPC_RECV_COMPOSING_STATE);
	return 0;
}
#endif

int xmppc_recv_composing(void)
{
	char buff[1024];
	int state = 0;
	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(buff, sizeof(buff));
	state = XMPPC_SEND_MESSAGE_STATE;
	set_state_to(state);
	return 0;
}

int xmppc_send_message(void)
{
	char message[1024];
	int state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	sprintf(message,"<message type='chat' id=%s to=%s><composing xmlns=%s/><body>%s</body></message>", ID,RECEIVE_ID,MESSAGE_XMLNS,MESSAGE);
	xmpp_write_to_server(message, strlen(message));

	state = XMPPC_RECV_MESSAGE_STATE;
	set_state_to(state);
	return 0;
}

int xmppc_recv_message(void)
{
	char buff[1024];
	int retval=0, state = 0;

	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(buff, sizeof(buff));
	buff[retval]='\0';
	XMPP_DEBUG("-->receive message :%s\n", buff);
	state = XMPPC_SEND_ACTIVE_STATE;
	set_state_to(state);
	return 0;
}

int xmppc_send_active(void)
{
	char active[1024];
	int state = 0;
	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	sprintf(active,"<message type='chat' id=%s to=%s><active xmlns=%s/></message>", ID, RECEIVE_ID,MESSAGE_XMLNS);
	xmpp_write_to_server(active, strlen(active));
	state = XMPPC_RECV_ACTIVE_STATE;
	set_state_to(state);
	return 0;
}

int xmppc_recv_active(void)
{
	char buff[1024];
	int state = 0;;
	XMPP_DEBUG("\n-->%d, %s, %s\n", __LINE__, __FUNCTION__, __FILE__);
	xmpp_read_from_server(buff, sizeof(buff));
	state = set_state_to(XMPPC_SEND_MESSAGE_STATE);
	set_state_to(state);
	return 0;
}

void xmpp_exit(void)
{
	//sleep(3);

	exit(1);
}

state_vector st_vect[] =
{
	{XMPPC_INIT_STATE, (void (*)(void)) xmppc_init_client},
	{XMPPC_SEND_VERSION_STATE, (void (*)(void)) xmppc_send_version},
	{XMPPC_SEND_STREAM_STATE, (void (*)(void)) xmppc_send_stream},
	{XMPPC_RECV_STREAM_ID_STATE, (void (*)(void)) xmppc_recv_streamid},
	{XMPPC_AUTH_OFFER_RECV_STATE, (void (*)(void)) xmppc_auth_offer_recv},
	{XMPPC_AUTH_SELECT_STATE, (void (*)(void)) xmppc_auth_select},
	{XMPPC_PLAIN_AUTH_STATE, (void (*)(void)) xmppc_do_plain_auth},
	{XMPPC_MD5_AUTH_STATE, (void (*)(void)) xmppc_do_md5_auth},
	{XMPPC_RECV_CHALLENGE_STATE,  (void (*)(void)) xmppc_recv_challenge},
	{XMPPC_SEND_CREDENTIAL_STATE, (void (*)(void)) xmpp_send_credentials},
	{XMPPC_AUTH_STATUS_STATE, (void (*)(void)) xmpp_recv_auth_status},
	{XMPP_SEND_EMPTY_RESPONSE, (void (*)(void)) xmpp_send_empty_response},
	//{XMPPC_RECV_SUCCESS, (void (*)(void)) xmpp_recv_success},
	{XMPPC_SEND_AGAIN_STREAM_STATE,(void(*)(void)) xmppc_send_second_time_stream},
	{XMPPC_RECV_ID_STATE,(void(*)(void)) xmppc_recv_second_id},
	{XMPPC_RECV_STREAM_FEATURES_STATE, (void(*)(void)) xmppc_recv_stream_features},
	//{XMPPC_RECV_ID, (void (*)(void)) xmpp_recv_session_id},
	//{XMPPC_SEND_STREAMS_STATE,(void(*)(void)) xmppc_send_streams},
	//{XMPPC_RECV_ID_STATE,(void(*)(void)) xmppc_recv_session_id},
	//{XMPPC_RECV_FEATURE_STATE, (void(*)(void)) xmppc_recv_session_feature},
	{XMPPC_SEND_ID_RESOURCE_STATE,(void(*)(void)) xmppc_send_id_resource},
	//{XMPPC_RECV_ID_RESOURCE_STATE,(void(*)(void)) xmppc_recv_id_resource},
	{XMPPC_RECV_JID_STATE,(void(*)(void)) xmppc_recv_jid},
	{XMPPC_SEND_SESSION_STATE, (void(*)(void)) xmppc_send_session},
	{XMPPC_RECV_SESSION_STATE, (void(*)(void)) xmppc_recv_session},
	{XMPPC_SEND_QUERY_ITEMS_STATE, (void(*)(void)) xmppc_send_query},
	{XMPPC_RECV_QUERY_ITEMS_STATE, (void(*)(void)) xmppc_recv_query},
	{XMPPC_SEND_QUERY_INFO_STATE, (void(*)(void)) xmppc_send_query_info},
	{XMPPC_RECV_QUERY_INFO_STATE, (void(*)(void)) xmppc_recv_query_info},
	{XMPPC_SEND_VCARD_STATE,(void(*)(void))xmppc_send_vcard},
	{XMPPC_RECV_VCARD_STATE,(void(*)(void))xmppc_recv_vcard},
	{XMPPC_SEND_LIST_STATE,(void(*)(void)) xmppc_send_list}, 
	{XMPPC_RECV_LIST_STATE,(void(*)(void)) xmppc_recv_list},
	{XMPPC_SEND_PRESENCE_STATE,(void(*)(void)) xmppc_send_presence}, 
	{XMPPC_RECV_PRESENCE_STATE,(void(*)(void)) xmppc_recv_presence}, 
	{XMPPC_SEND_AND_RECV_MESSAGES_STATE,(void(*)(void)) xmppc_msg_send_n_recv},

	{XMPPC_SEND_COMPOSING_STATE, (void(*)(void))  xmppc_send_composing},
	{XMPPC_RECV_COMPOSING_STATE, (void(*)(void))  xmppc_recv_composing},

	{XMPPC_SEND_MESSAGE_STATE,(void(*)(void)) xmppc_send_message}, 
	{XMPPC_RECV_MESSAGE_STATE,(void(*)(void)) xmppc_recv_message},

	{XMPPC_SEND_ACTIVE_STATE,(void(*)(void)) xmppc_send_active}, 
	{XMPPC_RECV_ACTIVE_STATE,(void(*)(void)) xmppc_recv_active},
#if 0
	{XMPPC_SEND_COMPOSE_STATE, (void(*)(void))  xmppc_send_compose},
	{XMPPC_RECV_COMPOSE_STATE, (void(*)(void))  xmppc_recv_compose},
	{XMPPC_SEND_MESSG_STATE,(void(*)(void)) xmppc_send_messg}, 
	{XMPPC_RECV_MESSG_STATE,(void(*)(void)) xmppc_recv_messg},
	{XMPPC_SEND_ACTIVES_STATE,(void(*)(void)) xmppc_send_actives}, 
	{XMPPC_RECV_ACTIVES_STATE,(void(*)(void)) xmppc_recv_actives},
#endif
	{XMPPC_EXIT_STATE, xmpp_exit}
};

void xmppc_execute_state_machine(void)
{
	int i = 0;

	for(; ;)
	{
		for (i = 0; i < sizeof(st_vect)/sizeof(state_vector); i++)
		{
			if (g_xmppc_state == st_vect[i].statevalue)
				st_vect[i].state_handler();
		}
	}
}


