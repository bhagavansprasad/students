
#include "structer.h"

int client_write(struct data * );  /*proto type of client_write*/

int rpc_send_req( struct data *p)
{
	int wretval;
	wretval = client_write(p);
	return (wretval);
}
