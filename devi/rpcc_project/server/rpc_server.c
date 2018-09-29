#include "unistd.h"
#include "structure.h"
#include "rpc_nets.h"

int main()
{  
	fop_data_req creq;
	fop_data_rep sreplay;
	int i = 0;
	init_nets_communication(SRVR_PORT);

	while(1)
	{
		server_read_from_client(&creq);

		process_client_request(&creq, &sreplay);

		server_write_to_client(&sreplay);

		if(creq.ope == 10)
			i++;
		if(i == 2)
			break;
	}

	close_nets_communication();
	return 0;
}
