#include <stdio.h>
#include "rpc_send_req.h"
#include "rpc_recv_req.h"
int rpc_send_req(struct rpcc *data, struct rpcs *reply)
{
	return rpc_recv_req(data, reply);
}

