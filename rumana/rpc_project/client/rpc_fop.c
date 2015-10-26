#include"strc.h"
int rpc_send_req(struct ch *q);
int rpcc_fop(struct ch *q)
{
int f;
f=rpc_send_req(q);
return f;
}

