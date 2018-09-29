#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include"struct_replay.h"
#include"struct_req.h"
#include"rpcs_send_req.h"
#include "srvr.h"

int main()
{
	int c=0;
	struct final c_req;
	struct S_final s_rply;

	printf("%d %s \n ",__LINE__,__FILE__);

	tcp_server_init();

	while(1)
	{
		server_read_data(&c_req);

		rpcs_rec_req(&c_req);
		if(c_req.op==5)
			c++;
		if(c==2)
			break;
	}
	close_socket();

}
