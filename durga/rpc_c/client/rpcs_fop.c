/*function for rpc_fop()*/

#include "structer.h"

int rpc_send_req (struct data *); /*proto type of rpc_send_req */

int rpcs_fop(struct data *p)
{
	int retval;
	retval = rpc_send_req( p);
}
