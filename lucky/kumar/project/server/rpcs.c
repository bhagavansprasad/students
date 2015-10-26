/********* SERVER CODE *********/
#include "rpc.h"
#include "nets.h"
#include "rpcs1.h"

int main()
{
	fop_data_req creq;
	fop_data_rep sreply;
	int retval=0;
	init_nets_communication(SRVR_PORT);

	while (1)
	{
		retval	= read_from_client(&creq);

		if (retval<=0)
			break;
		process_client_request(&creq,&sreply);

		write_to_client(&sreply);
	}

	close_nets_communication();
	return 0;
}
