#include <stdio.h>
#include"structer.h"
#include "server_structer.h"
int rpcs_fop(struct data * ,struct server *);

int rpc_recv_reqst( struct data *p, struct server *s)
{
	int retval;
	retval = rpcs_fop( p,s);
//	printf("-------->retval: %d\n",retval);
	return retval;
}
