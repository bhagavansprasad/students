#include<stdio.h>
#include<fcntl.h>
#include "rpc_fop.h"
#include "rpc_send_req.h"
int rpc_send_req(struct rpcc *data, struct rpcs *reply);
int rpcc_fop(struct rpcc *data,struct rpcs *reply)
{
    return rpc_send_req(data, reply);
}
