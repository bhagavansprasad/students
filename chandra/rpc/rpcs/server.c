#include <stdio.h>
#include "bits/errno.h"
#include <fcntl.h>
#include"reply_struct.h"
#include"req_struct.h"
void tcp_server_init();
int rpc_recv_req(struct rpcc *req, struct rpcs *reply);
int server_write_data(struct rpcs *reply);
int server_read_data(struct rpcc *req);
int main()
{
	struct rpcc req;
	struct rpcs reply;
	int c = 0;
	tcp_server_init();

	while(1)
	{
		server_read_data(&req);

		rpcs_recv_req(&req, &reply);
		server_write_data(&reply);
		if(req.op == 4)
			c++;
		if(c == 2)
			break;
	}
//	close_socket();
return 0;
}

