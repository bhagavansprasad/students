#include <stdio.h>
#include <fcntl.h>
#include "rpc_op.h"
int s_rpc_fop(fope_struct *pfdata, fope_struct_reply *preply)
{
	int fd,rval,wval,lval,t;
	struct open_data *popd=NULL;
	struct read_data *prdata=NULL;
	struct write_data *pwrdata=NULL;
	struct lseek_data *pldata=NULL;
	struct close_data *pcdata=NULL;

	printf("-->operation:%d\n",pfdata->operation);
	switch(pfdata->operation)
	{
		case RPC_OPEN:
			popd=&pfdata->udata.opdata;
			fd=open(popd->filename,popd->mode,popd->flags);
			printf("-->file:%s\n-->mode:%d\n-->flags:%d\n",popd->filename,popd->mode,popd->flags);
#if 0
			preply->operation = RPC_OPEN_REPLY;
	        
			preply->fd = popd->fd;

			return 0;

		case RPC_READ:
			prdata=&pfdata->udata.rrdata;
			rval=read(prdata->fd,prdata->buff,prdata->len);
			preply->operation = RPC_READ_REPLY;

			preply->rval=popd->rval;

			return 0;
		case RPC_WRITE:
			pwrdata=&pfdata->udata.wrdata;
			wval=write(pwrdata->fd,pwrdata->buff,pwrdata->rval);
			preply->operation = RPC_WRITE_REPLY;

			preply->wval = popd->wval;
			return 0;
		case RPC_LSEEK:
			pldata=&pfdata->udata.lsdata;
			lval = lseek(pldata->fd,pldata->filename,pldata->whence);
			preply->operation = RPC_LSEEK_REPLY;

			preply->lval = popd->lval;
			return 0;
		
		case RPC_CLOSE:
			 pcdata=&pfdata->udata.cldata;
			 close(pcdata->fd);
			 preply->operation = RPC_CLOSE_REPLY;

			 preply->fd = popd->fd;
			 return 0;
		
		default:
			printf("there is no file");
#endif
			break;
	}
}

