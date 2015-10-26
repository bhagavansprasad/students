#include <stdio.h>
#include "rpc_req.h"
#include "rpcc_fp.h"
int rpcs_fp(struct rpcc *data, struct reply_final *srf)
{
	printf("%d",data->op);

	switch(data->op)
	{
		case 1:
			srf->urd.ro.fd=open(data->u.o.fd, data->u.o.flag, data->u.o.mode);
			if(srf->urd.ro.fd == -1)
			{
				printf("file opening failed");	
			}
			return srf->urd.ro.fd;

		case 2:
			srf->urd.rr.fd=read(data->u.r.fp,data->u.r.buff, data->u.r.len);
			if(srf->urd.rr.fd == -1)
			{
				printf("file reading failed");	
			}

			return srf->urd.rr.fd;


		case 3:
			srf->urd.rw.fd=write(data->u.w.fp,data->u.r.buff,data->u.w.len);
			if(srf->urd.rw.fd == -1)
			{
				printf("file writing failed");	
			}

			return srf->urd.rw.fd;

		case 4:
			return(close(data->u.c.fd));

		default:
			printf("wrong value \n");
			break;
	}
}
