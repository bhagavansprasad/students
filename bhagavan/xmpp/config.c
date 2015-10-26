#include "xmppc.h"
#include  "config.h"
#include "string.h"

extern xmpp_context_block xmpp_cb;

int set_sock_fd(int fd)
{
	xmpp_cb.fd = fd;

	return 0;
}

int get_sock_fd()
{
	return xmpp_cb.fd;
}

int get_xmpp_server_ip(char *ip)
{
	strcpy(ip, XMPP_SERVER_IP);

	return 0;
}

int get_xmpp_server_port(void)
{
	return XMPP_SERVER_PORT;
}

int get_domain_name(char *dn)
{
	strcpy(dn, XMPP_DOMAIN_NAME);

	return 0;
}

int get_xmlns_name(char *xmlns)
{
	strcpy(xmlns, XMPP_XMLNS_NAME);

	return 0;
}

int get_xmlns_url_name(char *xmlns_url)
{
	strcpy(xmlns_url,XMLNS_URL);

	return 0;
}

int get_xmpp_str_id(char *xmlns_sid)
{
	strcpy(xmlns_sid,XMLNS_STRING_ID);

	return 0;
}

int get_user_name(char *uname)
{
	strncpy(uname, XMPPC_USER_NAME, strlen(XMPPC_USER_NAME));

	return 0;
}

int get_password(char *psword)
{
	strncpy(psword, XMPPC_PASSWORD, strlen(XMPPC_PASSWORD));

	return 0;
}

int get_cnonce(char *pcnonce)
{
	//strncpy(pcnonce, XMPPC_CNONCE, strlen(XMPPC_CNONCE));
	strncpy(pcnonce, XMPPC_CNONCE, 26);

	return 0;
}

int get_digest_uri(char *duri)
{
	strncpy(duri, DIGEST_URI, strlen(DIGEST_URI));

	return 0;
}

int get_resource(char *presource)
{
	strncpy(presource, RESOURCE_NAME, strlen(RESOURCE_NAME));

	return 0;
}

int get_nc_value(char *pnc)
{
	strncpy(pnc, NC_VALUE, strlen(NC_VALUE));

	return 0;
}

int get_auth_type()
{
	return AUTH_DIGEST_MD5;
}
