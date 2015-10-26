#include <stdio.h>
#include "rpc_req.h"
#include "rpc_fp.h"
int rpcs_fp(struct rpcc *data, struct reply_final *srf);

int rec_rpc_req(struct rpcc *data, struct reply_final *srf)
{
	int retval;
	retval = rpcs_fp(data, srf);
	printf("rec_fp retval =%d\n",retval);
	return retval;
}
