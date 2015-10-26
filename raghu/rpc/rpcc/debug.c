#include <stdio.h>
#include "rpc_fp.h"
void debug_before_write(struct rpcc *data)
{
	switch(data->op)
	{
		case 1: printf("data---> %s\n",data->u.o.fn);
				printf("flag---> %d\n",data->u.o.flag);
				printf("mode---> %d\n",data->u.o.mode);

		case 2: printf("file---> %d\n",data->u.r.fd);
			//	printf("buff---> %s\n",data->u.r.buff);
				printf("len---> %d\n",data->u.r.len);

		case 3: printf("file---> %d\n",data->u.w.fd);
				printf("buff---> %s\n",data->u.w.buff);
				printf("len---> %d\n",data->u.w.len);

		case 4: printf("flag---> %d\n",data->u.c.fd);
				
	}
}

