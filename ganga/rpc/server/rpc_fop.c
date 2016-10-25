#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rpc_fop.h"

int rpc_foperations(struct rpc_fop_data *prpcdata, struct rpc_fop_data_reply *reply);
{
	int retval = -1  ;
	int new_offset = -1;
	int fd = -1;

	switch (prpcdata->operation)
	{	
		case CRPC_OPEN_REQ:
			fd = open(prpcdata->udata.odata.fname, prpcdata->udata.odata.mode, prpcdata->udata.odata.flags);
			reply->operation = RPC_OPEN_REQ_REPLY;
			reply->udata.oreply.fd = fd;
			return fd;

		case CRPC_READ_REQ:
			retval = read(prpcdata->udata.rdata.fd, prpcdata->udata.rdata.buff, prpcdata->udata.rdata.size);
			return retval;

		case CRPC_WRITE_REQ:	
			retval = write(prpcdata->udata.wdata.fd, prpcdata->udata.wdata.buff, prpcdata->udata.wdata.size);
			return retval;

		case CRPC_LSEEK_REQ:
			new_offset = lseek(prpcdata->udata.sdata.fd, prpcdata->udata.sdata.off_set, prpcdata->udata.sdata.whence);
			return new_offset;

		case CRPC_CLOSE_REQ:
			return close(fd);

		default:
			printf("there is no file:\n");
			break;
	}
}
