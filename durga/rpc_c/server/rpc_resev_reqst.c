#include "server_accept.h"

int rpc_resev_requst ( struct data *p)
{
	server_read( p );
	return (rpcs_fop(p));
}

