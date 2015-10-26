#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"unistd.h"


#define AUTH_PLAIN 1 
#define AUTH_DIGEST_MD5 2 
#define AUTH_MECHANISAM_TYPES 5
#define NONCE_LEN 256
#define XMPP_ID_LEN 1024
#define UNAME_LEN 256
#define PASS_LEN 256
#define REALM_LEN 256
typedef enum state_num_t {
	XMPPC_INVALID_STATE = 0,
	XMPPC_INIT_STATE = 1,
	XMPPC_SEND_VERSION_STATE = 2,
	XMPPC_SEND_STREAM_STATE = 3,
	XMPPC_RECV_STREAM_ID_STATE = 4,
	XMPPC_AUTH_OFFER_RECV_STATE = 5,
	XMPPC_AUTH_SELECT_STATE = 6,
	XMPPC_PLAIN_AUTH_STATE = 7,
	XMPPC_MD5_AUTH_STATE = 8,
	XMPPC_RECV_CHALLENGE_STATE = 9,
	XMPPC_SEND_CREDENTIAL_STATE = 10,
	XMPPC_AUTH_STATUS_STATE = 11,
	XMPP_SEND_EMPTY_RESPONSE = 12,
	XMPPC_RECV_SUCCESS = 13,
	XMPPC_SEND_AGAIN_STREAM_STATE = 14,
	XMPPC_RECV_ID_STATE = 15,
	XMPPC_RECV_STREAM_FEATURES_STATE = 16,
	XMPPC_SEND_ID_RESOURCE_STATE = 17,
	XMPPC_RECV_JID_STATE = 18,
	XMPPC_SEND_SESSION_STATE = 19,
	XMPPC_RECV_SESSION_STATE = 20,
	XMPPC_SEND_QUERY_ITEMS_STATE = 21,
	XMPPC_RECV_QUERY_ITEMS_STATE = 22,
	XMPPC_SEND_QUERY_INFO_STATE = 23,
	XMPPC_RECV_QUERY_INFO_STATE = 24,
	XMPPC_SEND_VCARD_STATE = 25,
	XMPPC_RECV_VCARD_STATE = 26,
	XMPPC_SEND_LIST_STATE = 27,
	XMPPC_RECV_LIST_STATE = 28,
	XMPPC_SEND_PRESENCE_STATE = 29,
	XMPPC_RECV_PRESENCE_STATE = 30,
	XMPPC_SEND_COMPOSING_STATE = 31,
	XMPPC_RECV_COMPOSING_STATE = 32,
	XMPPC_SEND_MESSAGE_STATE = 33, 
	XMPPC_RECV_MESSAGE_STATE = 34,
	XMPPC_SEND_ACTIVE_STATE = 35,
	XMPPC_RECV_ACTIVE_STATE = 36,
	XMPPC_SEND_AND_RECV_MESSAGES_STATE = 37,
#if 0
	XMPPC_SEND_COMPOSE_STATE,
	XMPPC_RECV_COMPOSE_STATE,
	XMPPC_SEND_MESSG_STATE, 
	XMPPC_RECV_MESSG_STATE,
	XMPPC_SEND_ACTIVES_STATE,
	XMPPC_RECV_ACTIVES_STATE,
#endif
	XMPPC_EXIT_STATE 
}state_num;

typedef struct state_vector_t
{
	int statevalue;
	void (*state_handler)(void);
}state_vector;


typedef struct context_block
{
	int fd;
	char id[XMPP_ID_LEN];
	int auth_mech_offered[AUTH_MECHANISAM_TYPES];
	int auth_mech_opted;
	char auth_offer[125];
	char mech[256];

	//User credentials
	char username[UNAME_LEN];
	char password[PASS_LEN];

	//temparary members
	char a2[1024];

	char c_buff[1024];

	//Gets populated from challenge
	char realm[REALM_LEN];
	char nonce[NONCE_LEN];
	int  nonce_len;
	char qop[120];
	char charset[256];

	char cnonce[NONCE_LEN];
	int nc;
	char max_buf[125];
	char digest_uri[256];
}xmpp_context_block;
