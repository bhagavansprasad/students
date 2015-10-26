enum {

      INIT_CONN_STATE = 0,
      SEND_VERSION,
      XMPP_SEND_STREAM,
      XMPP_RECV_STREAMID_STATE
      XMPP_AUTH_OFFER_RECV_STATE,
      XMPP_AUTH_STATE,
      XMPP_PLAIN_AUTH_STATE,
      XMPP_MDS_AUTH_STATE,
      XMPP_RECV_CHALLENGE,
      XMPP_SEND_CREDENTIAL_STATE,
      XMPP_AUTH_SUCCESFULL,
    };



int init_conn_state( int port)
{
	int sfd = socket(int domain,int type,int protocal);      /socket creates a end point connection
        connect(sfd,struct *sock addr,sizeof(sock addr));  /connection establish to server
        set state to SEND_VERSION;
}


int send_version(int xml version,int fd)
{
        build xml string,
        send version ,
        set state to XMPP_SEND_STREAM,
}


Int xmpp_send_stream(int fd)
{
        build xml stream string,
        send string,
        set send to XMPP_RECV_STREAMID_STATE,
}


int xmpp_recv_streamid_state(char *buff)
{

                 parse a xml string ,
                 set send XMPP_AUTH_OFFER_RECV_STATE,
}


int xmpp_auth_offer_recv_state(char *buff)
{
     send to XMPP_AUTH_STATE,

}


int xmpp_auth_state(char *buff)
{

	parse recv string 

	if(mechanisam == PLAIN)
	set XMPP_PLAIN_AUTH_STATE,
	else if(mechanisam == MDS)
	XMPP_MDS_AUTH_STATE,
}
'

int xmpp_plain_auth_state(int fd)
{

	build authentication string with plain text,
	send authentication plain text,
        send to XMPP_RECV_CHALLENGE,
}


int xmpp_mds_auth_state(int fd)
{
	
	build authentication string with mds digest text,
	send authentication md5 text,
        send to XMPP_RECV_CHALLENGE,
}


int xmpp_recv_challenge(char *buff)

{
     parse the chalenge string,
     set to XMPP_SEND_CREDENTIAL_STATE,
}


int xmpp_send_credential_state(int fd)
{
      build response string,
      send response string to server,
      XMPP_AUTH_SUCCESFULL,
}
      
