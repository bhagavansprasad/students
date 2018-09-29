#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "struct.h"
#include "rpcs.h"
#include "structrep.h"
#include <string.h>
//int server_reply_data(struct server *s);


int server_read_data(struct fds *a_fds)
{
	int  fdo,fdr,fdw,fdc;
//	struct server s;
	printf("server Type: %d\n",a_fds->type);
	switch (a_fds->type)
	{
		case 1:
			printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
			fdo = s_open(a_fds->a_uns.a_open_d1.pathname,
					a_fds->a_uns.a_open_d1.flags,a_fds->a_uns.a_open_d1.mode);
			
			printf("-->fd_open :%d\n", fdo);
			//return fdo;
//			s.type=1;
//			s.a_uns.o.fd=fdo;
//			 server_reply_data(&s);
				break;
				
		case 2:
			printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
			fdr = s_read(a_fds->a_uns.a_read_d2.fd,
					a_fds->a_uns.a_read_d2.buff, a_fds->a_uns.a_read_d2.count);

			printf("-->fd_read :%d\n", fdr);
//					s.type=2;
//					s.a_uns.r.rval=fdr;
//				strcpy(s.a_uns.r.buff,a_fds->a_uns.a_read_d2.buff);
//			 server_reply_data(&s);

		//	return fdr;
				break;

		case 3:
			printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
			fdw = s_write(a_fds->a_uns.a_write_d3.fd,
					a_fds->a_uns.a_write_d3.buff,a_fds->a_uns.a_write_d3.count);
			
			printf("-->fd_write :%d\n", fdw);
//				s.type=3;
//				s.a_uns.w.rval=fdw;
//				 server_reply_data(&s);

			//return fdw;
				break;

		case 4:
			printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
			fdc = s_close(a_fds->a_uns.a_close_d4.fd);
			
			printf("-->fd_close :%d\n", fdc);
//			s.type=4;
//			s.a_uns.c.rval=fdc;
//			server_reply_data(&s);
			break;

		default:
			printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
			printf("-->Invalid MODE\n");
		
	}
}



