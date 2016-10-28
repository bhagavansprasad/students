#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../defs/rpc_fop.h"

int rpc_foperations(struct rpc_fop_data *prpcdata, struct rpc_fop_data_reply *preply)
{
	int retval = -1 ;
	int new_off_set = -1 ;
	int fd = -1 ;
	int byte_count = -1;

	printf("-->S. %s %s %d\n", __FILE__, __FUNCTION__, __LINE__); 

	printf("-->S. operation :%d\n", prpcdata->operation); 

	switch (prpcdata->operation)
	{	
		case CRPC_OPEN_REQ:
			printf("-->S. fname :%s, mode :%d, flags :%d\n", prpcdata->udata.odata.fname, prpcdata->udata.odata.mode, prpcdata->udata.odata.flags);
			fd = open(prpcdata->udata.odata.fname, prpcdata->udata.odata.mode, prpcdata->udata.odata.flags);
			printf("-->S: open retval :%d\n", fd);
			preply->operation = CRPC_OPEN_REQ_REPLY;
			preply->ureply.oreply.fd = fd;
			printf("-->S. OPEN_REQ_REPLY--> %d\n", fd);

			return preply->ureply.oreply.fd;

		case CRPC_READ_REQ:
			printf("-->S. fd :%d, buff :%s, len :%d\n", prpcdata->udata.rdata.fd, prpcdata->udata.rdata.buff, prpcdata->udata.rdata.size);
			retval = read(prpcdata->udata.rdata.fd, prpcdata->udata.rdata.buff, prpcdata->udata.rdata.size);

			printf("-->S: read retval :%d\n", retval);
			prpcdata->udata.rdata.buff[retval] = '\0';
			preply->operation = CRPC_READ_REQ_REPLY;
			preply->ureply.rreply.byte_count = byte_count;
			printf("-->S. READ_REQ_REPLY--> %d\n", byte_count);

			return preply->ureply.rreply.byte_count;

		case CRPC_WRITE_REQ:	
			retval = write(prpcdata->udata.wdata.fd, prpcdata->udata.wdata.buff, prpcdata->udata.wdata.size);
			printf("-->S: write retval :%d\n",retval);
			
			preply->operation = CRPC_WRITE_REQ_REPLY;
			preply->ureply.wreply.byte_count = byte_count;
			printf("WRITE_REQ_REPLY--> %d\n", byte_count);

			return preply->ureply.wreply.byte_count;

		case CRPC_LSEEK_REQ:
			new_off_set = lseek(prpcdata->udata.sdata.fd, prpcdata->udata.sdata.off_set, prpcdata->udata.sdata.whence);
			printf("-->S: lseek retval :%d\n",new_off_set);
			
			preply->operation = CRPC_LSEEK_REQ_REPLY;
			preply->ureply.sreply.new_off_set = new_off_set;
			printf("LSEEK_REQ_REPLY--> %d\n", new_off_set);
			
			return preply->ureply.sreply.new_off_set;

		case CRPC_CLOSE_REQ:
			
			preply->operation = CRPC_CLOSE_REQ_REPLY;
			preply->ureply.creply.retval = retval;
			printf("CLOSE_REQ_REPLY--> %d\n", retval);
			
			return preply->ureply.creply.retval;

		default:
			printf("there is no file:\n");
			break;
	}
}
