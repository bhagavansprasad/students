#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../inc/rpc_op.h"
int s_rpc_fop(fope_struct *pfdata,fope_struct_reply *preply)
{
	int fd,rval,wval,lval,t;
	struct open_data *popd=NULL;
	struct read_data *prdata=NULL;
	struct write_data *pwrdata=NULL;
	struct lseek_data *pldata=NULL;
	struct close_data *pcdata=NULL;
	printf("-->S,%d,%s,%s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("-->S: operation:%d\n",pfdata->operation);
	switch(pfdata->operation)
	{
		case RPC_OPEN:
			popd=&pfdata->udata.opdata;
			printf("-->S. RPC_OPEN: file:mode:flags: %s:%d:flags:%d\n", popd->filename, popd->mode, popd->flags);
			fd=open(popd->filename,popd->mode,popd->flags);

			preply->operation = RPC_OPEN_REPLY;

			preply->udata.op_reply.fd=fd;
			printf("-->S. RPC_OPEN: fd:%d\n", fd);
			return preply->udata.op_reply.fd;

	case RPC_READ:
			prdata=&pfdata->udata.rrdata;
			//printf("-->S. RPC_READ: file:mode:flags: %s:%d:flags:%d\n", popd->filename,popd->mode,popd->flags);
			prdata=&pfdata->udata.rrdata;
			rval=read(prdata->fd,prdata->buff,prdata->len);
			preply->operation = RPC_READ_REPLY;

			preply->udata.rr_reply.rval=rval;
            printf("--->S:RPC_READ:rval:%d\n\n",rval);
			return preply->udata.rr_reply.rval;

		case RPC_WRITE:
			//printf("-->S. RPC_WRITE: file:mode:flags: %s:%d:flags:%d\n", popd->filename,popd->mode,popd->flags);
			pwrdata=&pfdata->udata.wrdata;
			wval=write(pwrdata->fd,pwrdata->buff,pwrdata->rval);
			preply->operation = RPC_WRITE_REPLY;

			preply->udata.wr_reply.wval=wval;
			printf("--->S:RPC_WRITE:wval:%d\n\n",wval);
			return preply->udata.wr_reply.wval;

		case RPC_LSEEK:
			//printf("-->S. RPC_WRITE: file:mode:flags: %s:%d:flags:%d\n", popd->filename,popd->mode,popd->flags);
			pldata=&pfdata->udata.lsdata;
			lval = lseek(pldata->fd, pldata->filename, pldata->whence);
			preply->operation = RPC_LSEEK_REPLY;

			preply->udata.ls_reply.lval=lval;
			printf("--->S:RPC_LSEEK:lval:%d\n\n",lval);
			return preply->udata.ls_reply.lval;

		case RPC_CLOSE:
			//printf("-->S. RPC_close: file:mode:flags: %s:%d:flags:%d\n", popd->filename,popd->mode,popd->flags);
			pcdata=&pfdata->udata.cldata;
			close(pcdata->fd);
			preply->operation = RPC_CLOSE_REPLY;

			preply->udata.cl_reply.fd=fd;
			printf("--->S:RPC_CLOSE:fd:%d\n\n",fd);
			return preply->udata.cl_reply.fd;

		default:
			printf("there is no file");
			break;
	}
}

