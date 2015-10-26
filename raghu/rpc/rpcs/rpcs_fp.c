#include <stdio.h>
#include "rpc_req.h"
#include "rpc_fp.h"
#include "string.h"

int rpcs_fp(struct rpcc *data, struct reply_final *srf)
{
	printf("------>final operation %d\n", data->op);

	switch(data->op)
	{
		case 1:
			srf->urd.ro.fd=open(data->u.o.fd, data->u.o.flag, data->u.o.mode);
			if(srf->urd.ro.fd == -1)
			{
				printf("file opening failed");	
			}
			
			printf("in path open fd is : %s\n",data->u.o.fd);
			printf("in final fd is : %d\n",srf->urd.ro.fd);

			return srf->urd.ro.fd;

		case 2:
			srf->urd.rr.fd=read(data->u.r.fp,data->u.r.buff, data->u.r.len);
			data->u.r.buff[srf->urd.rr.fd] ='\0';
			printf("buff----->%s\n",data->u.r.buff);
			if(srf->urd.rr.fd == -1)
			{
				printf("file reading failed\n");	
			}
			strcpy(srf->urd.rr.buff,data->u.r.buff);
			printf("buff----->%s\n",srf->urd.rr.buff);
			return srf->urd.rr.fd;


		case 3:
			srf->urd.rw.fd=write(data->u.w.fp,data->u.w.buff,data->u.w.len);
			if(srf->urd.rw.fd == -1)
			{
				printf("file writing failed\n");	
			}

			return srf->urd.rw.fd;

		case 4:
			return(close(data->u.c.fd));

		default:
			printf("wrong value \n");
			break;
	}
}
