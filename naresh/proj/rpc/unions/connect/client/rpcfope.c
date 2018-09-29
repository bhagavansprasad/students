#include "arpc.h"
int rpcc_send_data(fopdata_req *req);
int rpcc_fope(fopdata_req *req)
{
	int retval = -1;

	retval = rpcc_send_data(req);

	return retval;
}
