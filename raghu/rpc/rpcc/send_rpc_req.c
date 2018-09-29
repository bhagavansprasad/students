//void client_write_data(struct rpcc *data, struct reply_final *srf);
#include <stdio.h>
#include "rpc_fp.h"
#include "rpc_req.h"
int client_write_data(struct rpcc *);
int send_rpc_req(struct rpcc *data, struct reply_final *srf)
{
	int wretval,rretval;
	wretval=client_write_data(data);
//	printf("in send Wretval of client=%d\n",wretval);
	return 0;
}

