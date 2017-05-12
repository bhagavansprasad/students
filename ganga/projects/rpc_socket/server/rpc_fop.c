#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../defs/rpc_fop.h"

int rpc_foperations(struct rpc_fop_data *prpcdata, struct rpc_fop_data_reply *preply)
{
	int retval = -1 ;
	int new_off_set = -1 ;
	int fd = -1 ;
	int byte_count = -1;
	char buff[100];

	printf("\n");
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
			printf("-->S. OPEN_REQ_REPLY--> %d\n", prpcdata->operation );
			printf("-->S: open reply_retval :%d\n", fd);

			return preply->ureply.oreply.fd;

		case CRPC_READ_REQ:
			printf("-->S. fd  :%d\n", prpcdata->udata.rdata.fd);
			printf("-->S. len :%d\n", prpcdata->udata.rdata.size);
			retval = read(prpcdata->udata.rdata.fd, prpcdata->udata.rdata.buff, prpcdata->udata.rdata.size);
			prpcdata->udata.rdata.buff[retval] = '\0';
			strcpy(buff, prpcdata->udata.rdata.buff);
			printf("-->S: read buff :%s\n", prpcdata->udata.rdata.buff);

			preply->operation = CRPC_READ_REQ_REPLY;
			preply->ureply.rreply.retval = retval;
			printf("-->S: read reply retval :%d\n", retval);
			strcpy(preply->ureply.rreply.buff, buff);
			printf("-->S: read reply buff :%s\n", preply->ureply.rreply.buff);

			return preply->ureply.rreply.retval;

		case CRPC_WRITE_REQ:	
			printf("-->S. fd :%d, buff :%s, len :%d\n", prpcdata->udata.wdata.fd, prpcdata->udata.wdata.buff, prpcdata->udata.wdata.size);
			retval = write(prpcdata->udata.wdata.fd, prpcdata->udata.wdata.buff, prpcdata->udata.wdata.size);
			printf("-->S: write retval :%d\n",retval);
			
			preply->operation = CRPC_WRITE_REQ_REPLY;
			printf("WRITE_REQ_REPLY--> %d\n", preply->operation);
			preply->ureply.wreply.retval = retval;
			printf("-->S: writereply_ retval :%d\n", retval);

			return preply->ureply.wreply.retval;

		case CRPC_LSEEK_REQ:
			printf("-->S. fd :%d, off_set :%d, whence :%d\n", prpcdata->udata.sdata.fd, prpcdata->udata.sdata.off_set,prpcdata->udata.sdata.whence);
			new_off_set = lseek(prpcdata->udata.sdata.fd, prpcdata->udata.sdata.off_set, prpcdata->udata.sdata.whence);
			printf("-->S: lseek retval :%d\n",new_off_set);
			
			preply->operation = CRPC_LSEEK_REQ_REPLY;
			preply->ureply.sreply.new_off_set = new_off_set;
			printf("-->S. LSEEK_REQ_REPLY--> %d\n", preply->operation );
			printf("-->S:  lseek reply_retval :%d\n", new_off_set);
			
			return preply->ureply.sreply.new_off_set;

		case CRPC_CLOSE_REQ:
			printf("-->S. fd :%d\n", prpcdata->udata.cdata.fd);
			fd = close(prpcdata->udata.cdata.fd);
			printf("-->S: close retval :%d\n",fd);
			
			preply->operation = CRPC_CLOSE_REQ_REPLY;
			printf("CLOSE_REQ_REPLY--> %d\n", preply->operation);
			preply->ureply.creply.fd = fd;
			printf("-->S: close reply_retval :%d\n", fd);
			
			return preply->ureply.creply.fd;

		default:
			printf("there is no file:\n");
			break;
	}

}
