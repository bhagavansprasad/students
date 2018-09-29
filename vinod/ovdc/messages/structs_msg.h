typedef struct operations
{
	int pid;
	int first,second;
	char cmnd[10];
}op;

typedef struct server_reply
{
	int rpid;
	int result;
}reply;
