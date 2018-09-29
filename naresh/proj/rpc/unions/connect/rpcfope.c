#include "rccfpoe.h"
int rpcc_send_data(fopdata *r);
int rpcc_fope(fopdata *r)
{
	int retval = -1;

	retval = rpcc_send_data(r);

	return retval;
}
