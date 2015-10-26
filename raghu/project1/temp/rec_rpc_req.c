#include <stdio.h>
#include "rpc_req.h"
#include "rpcc_fp.h"

int rec_rpc_req(struct rpcc *data, struct reply_final *srf)
{
	return rpcs_fp(data, srf);
}
