#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "rpc_req.h"
#include "rpc_fp.h"

int rec_rpc_req(struct rpcc *data, struct reply_final *srf);
int server_write(struct reply_final *srf);
void tcp_server();
int server_read(struct rpcc *data);

int main()
{
	int c=0;
	struct rpcc data;
	struct reply_final srf;

	tcp_server();

	while(1)
	{
		server_read(&data);
		rec_rpc_req(&data, &srf);
		server_write(&srf);
		
		if(data.op == 4)
			c++;

		if(c==2)
			break;
	}
	return 0;
}
