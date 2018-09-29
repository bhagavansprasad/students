#include "struct_client.h"

int rpc_send_req(struct fop_data_t *fop_data);

int rpcc_fop(struct fop_data_t *fop_data)
{
	int retval = 0;

	retval = rpcc_send_req(fop_data);

//	printf("-->After writing to socket retval :%d\n", retval);
}
