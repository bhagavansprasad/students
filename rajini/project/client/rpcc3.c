
#include "rpc.h"
int rpcc_send_data(fop_data_req *preq);
int write_to_server(fop_data_req *pcreq);
fop_data_req preq;
int rpcc_fope(fop_data_req *preq)
{
	int retval = -1;
//	fop_data_rep sreply;

//	retval = rpcc_send_data(preq);
	//retval = read_from_server(&sreply);
    
retval= write_to_server(preq);


	return retval;
} 
