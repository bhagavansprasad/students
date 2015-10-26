#include <stdio.h>
#include "rpcs_fop.h"
int rpc_recv_req(struct rpcc *data, struct rpcs *reply)
{
	return rpcs_fop(data, reply);
}

