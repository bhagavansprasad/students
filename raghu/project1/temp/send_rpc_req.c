#include <stdio.h>
#include "rpc_req.h"
#include "rpcc_fp.h"
int send_rpc_req(struct rpcc *data, struct reply_final *srf)
{
	return rec_rpc_req(data, srf);
}
