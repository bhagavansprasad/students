#include "rpc.h"
#include "fop1.h"
int write_to_server(fop_data_req *preq);

int rpcc_send_data(fop_data_req *preq);

fop_data_req preq;
int rpcc_fop(fop_data_req *preq)
{
	int retval = -1;

	rpcc_send_data(preq);
	retval = write_to_server(preq);
		
	return retval;
} 
