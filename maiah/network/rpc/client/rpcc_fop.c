#include "stdio.h"
#include "arpc.h"
#include "rpcc_net.h"

int rpcc_fop(fop_data_req *pcdata)
{
	int retval = 0;

	retval = rpcc_send_req(pcdata);

	printf("-->After writing to socket retval :%d\n", retval);

	return retval;
}
