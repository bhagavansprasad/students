#include <stdio.h>
#include <fcntl.h>
#include "rpcc_fp.h"
#include "rpc_req.h"
int rpcc_fop(struct rpcc *data)
{
/*	int fd,fp;
	switch(data->op)
	{
		case 1:

			fd=open(data->u.o.fn, data->u.o.flag, data->u.o.mode);
			return fd;
			break;
		case 2:fp=read(data->u.r.fp,data->u.r.buff,data->u.r.len);
			   return fp;
			   break;
		case 3:return(write(data->u.w.fp,data->u.r.buff,data->u.w.len));
		break;
		case 4:return(close(data->u.c.fn));
		break;
		default:printf("wrong value \n");
	}*/

	struct reply_final srf;

	return send_rpc_req(data, &srf);
}
