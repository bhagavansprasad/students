#include "rpc.h"
#include "fop1.h"
//int rpcc_send_data(fop_data_req *preq);
int write_to_server(fop_data_req *pcreq);
fop_data_req pcreq;
int rpcc_fop(fop_data_req *pcreq)
{
	int retval = -1;

//	rpcc_send_data(preq);
	retval = write_to_server(pcreq);

	return retval;
} 
