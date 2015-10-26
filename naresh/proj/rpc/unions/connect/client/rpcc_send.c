#include "rpccfop.h"

int rpc_send_req(fopdata *r);

int rpcc_fop(fopdata *r)
{
	int retval = 0;

	retval = rpcc_send_req(r);
}
