/********* SERVER CODE *********/
#include <rpc.h>
#include "nets.h"
#include "rpcs3.h"


int main()
{
	fop_data_req creq;
	fop_data_rep sreply;
	init_nets_communication(SRVR_PORT);

	while (1)
	{
		read_from_client(&creq);

		process_client_request(&creq, &sreply);
		write_to_client(&sreply);

		break;
	}

	close_nets_communication();

	//aread()

	return 0;
}
