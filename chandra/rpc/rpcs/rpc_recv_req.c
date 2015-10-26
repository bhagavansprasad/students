#include <stdio.h>
#include "req_struct.h"
#include "reply_struct.h"
#include "rpcs_fop.h"

int rpcser_fop(struct rpcc *req, struct rpcs *reply);

int rpcs_recv_req(struct rpcc *req, struct rpcs *reply)
{
	//struct rpcs reply;
	int retval;

	retval = rpcser_fop(req, reply);
	printf("rpcser_fop retval : %d\n", retval);
		//retval = server_write_data(&reply);
		//return retval;

}
