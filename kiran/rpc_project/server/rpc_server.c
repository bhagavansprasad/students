#include "unistd.h"
#include "structure.h"
#include "rpc_nets.h"

int main()
{  
	fop_data_req creq;
	fop_data_rep sreplay;
	int retval = 0;
	init_nets_communication(SRVR_PORT);
	while(1)
	{
		retval = server_read_from_client(&creq);
		if (retval <= 0)
			break;

		process_client_request(&creq, &sreplay);

		server_write_to_client(&sreplay);

	}

	close_nets_communication();
	return 0;
}
