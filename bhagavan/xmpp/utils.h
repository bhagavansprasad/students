
#define XMPP_DBUG_INFO

#ifdef XMPP_DBUG_INFO
#define XMPP_DEBUG printf
#else
#define XMPP_DEBUG
#endif

int xmpp_write_to_server(char *buff, int len);
int parse_realm(char *tbuff, char *prealm);
int parse_nonce(char *tbuff, char *pnonce);
int parse_qop(char *tbuff, char *pqop);
int parse_charset(char *tbuff, char *pchar_set);
int parse_challange(char *tbuff, int len, char *pchallange, int *pchallenge_len);
int xmpp_write_to_server(char *buff, int len);
int xmpp_read_from_server(char *buff, int len);

