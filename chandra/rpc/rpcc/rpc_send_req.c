#include <stdio.h>
#include "req_struct.h"
#include "reply_struct.h"


int client_send_req(struct rpcc *);

int rpc_send_req(struct rpcc *req)
{
	return client_send_req(req);
}


int rpc_read_req(struct rpcs *reply)
{
	int retval = -1;
	retval = client_read_req(reply);
	printf("client_read_reply retval is : %d\n", retval);
}

