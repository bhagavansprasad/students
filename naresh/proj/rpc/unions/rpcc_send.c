#include "rpccfop.h"

int rpc_send_req(struct naresh *r);

int rpcc_fop(struct naresh *r)
{
	int retval = 0;

	retval = rpcc_send_req(q);

	printf("-->after writing to socket retval :%d\n",retval);
}
