#include "struct_client.h"
int rpc_send_req(struct ch *q)
{
	int wd;

	wd = client(q);

	return wd;
}
