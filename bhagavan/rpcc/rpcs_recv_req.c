#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include"req_defs.h"

#include"rpcs.h"

int rpc_reciv(struct fds *b_fds)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

	int  fd9,retval1,reval2,reval3;

	switch (b_fds->type)
	{
		case 1:
			fd9 = s_open(b_fds->a_uns.a_open_d1.pathname,
					b_fds->a_uns.a_open_d1.flag,b_fds->a_uns.a_open_d1.mode);
			printf("fd9:%d\n",fd9);
			return fd9;

		case 2:
			retval1=s_read(b_fds->a_uns.a_read_d2.fd1,
					b_fds->a_uns.a_read_d2.buff, b_fds->a_uns.a_read_d2.count);

			return retval1;

		case 3:
			reval2=s_write(b_fds->a_uns.a_write_d3.fd2,
					b_fds->a_uns.a_write_d3.buff,b_fds->a_uns.a_write_d3.count);
			return reval2;

		case 4:
			reval3=s_close(b_fds->a_uns.a_close_d4.fd);
			return reval3;

		default:
			printf("-->Invalid MODE\n");
	}
}



