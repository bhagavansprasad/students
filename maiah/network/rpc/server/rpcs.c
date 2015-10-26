#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "rpcs_net.h"
#include "arpc.h"
#include "rpcs.h"

int main()
{
	fop_data_req client_data;
	fop_data_rep server_data;
	int *pcdata,*psdata;

	server_comm(SRVR_PORT);

	while(1)
	{
		rpcs_recv_data(client_data);

		//printf("%u\n",&client_data);

		//rpcs_process_fop_request(client_data, server_data);
        rpcs_process_fop_request(fop_data_req *pcdata, fop_data_rep *psdata)

		//rpcs_send_req(&server_data);

		break;
	}

	return 0;
}
