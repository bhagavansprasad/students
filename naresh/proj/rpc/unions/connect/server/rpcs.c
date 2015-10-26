/*****SERVER CODE*****/

#include "arpc.h"
#include "nets.h"
#include "rpcs.h"

int main()
{
	fopdata_req pcreq;
	fopdata_rep preply;
	init_net_comm(SRVR_PORT);

	while (1)
	{	
		read_from_client(&pcreq);

	    process_client_request(&pcreq, &preply);

		write_to_client(&preply);

		break;
	}

	close_net_communication();

	//aread()

	return 0;
}
