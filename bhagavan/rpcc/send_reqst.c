#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include "req_defs.h"
#include "string.h"
#include "rpcs_recv_req.h"

int rpc_send(struct fds *a_fds)
{
	rpc_reciv(a_fds);
}

#if 0
	switch (a_fds->type)
	{
		case 1:
			//	struct newfds b_fds;

			b_fds.type=1;
			strcpy(b_fds.a_uns.a_open_d1.pathname,a_fds->a_uns.a_open_d1.pathname);
			b_fds.a_uns.a_open_d1.flag=a_fds->a_uns.a_open_d1.flag;
			b_fds.a_uns.a_open_d1.mode=a_fds->a_uns.a_open_d1.mode;

			return rpc_reciv(a_fds);
		case 2:
			//	struct newfds b_fds;

			b_fds.type=2;
			b_fds.a_uns.a_read_d2.fd1=a_fds->a_uns.a_read_d2.fd1;
			b_fds.a_uns.a_read_d2.count=a_fds->a_uns.a_read_d2.count;

			retval =  rpc_reciv(&b_fds);
			strncpy(b_fds.a_uns.a_read_d2.buff,a_fds->a_uns.a_read_d2.buff, retval);

			return retval;
		case 3:
			//	struct newfds b_fds;

			b_fds.type=3;
			b_fds.a_uns.a_write_d3.fd2=a_fds->a_uns.a_write_d3.fd2;
			strcpy(b_fds.a_uns.a_write_d3.buff,a_fds->a_uns.a_write_d3.buff);
			b_fds.a_uns.a_write_d3.count=a_fds->a_uns.a_write_d3.count;

			rpc_reciv(&b_fds);

			return 0;
		case 4:
			//	struct newfds b_fds;

			b_fds.type=4;
			b_fds.a_uns.a_close_d4.fd=a_fds->a_uns.a_close_d4.fd;

			rpc_reciv(&b_fds);

			return 0;
	}
}
#endif
