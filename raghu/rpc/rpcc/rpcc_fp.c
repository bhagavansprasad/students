#include <stdio.h>
#include <fcntl.h>
#include "rpc_fp.h"
#include "rpc_req.h"
int send_rpc_req(struct rpcc *,struct reply_final *);

int rpcc_fop(struct rpcc *data)
{
	struct reply_final srf;
	return send_rpc_req(data, &srf);
}
