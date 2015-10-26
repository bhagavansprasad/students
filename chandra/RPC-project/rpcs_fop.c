#include <stdio.h>
#include "rpc_fop.h"
#include "rpc_send_req.h"
int rpcs_fop(struct rpcc *data, struct rpcs *reply)
{
	printf("final data operation is : %d\n",data->op);

	switch(data->op)

	{

		case 1 : 
			reply -> ru.ro.rfd = open(data -> u.o.rfd, data -> u.o.flags, data -> u.o.mode);
			return(reply -> ru.ro.rfd);
			break;

		case 2 :
			reply -> ru.rr.rfd = read(data -> u.r.rfd, data -> u.r.buff, data -> u.r.len);
			return(reply -> ru.rr.rfd);
			break;

		case 3 : 
			reply -> ru.rw.wfd = write(data -> u.w.wfd, data -> u.w.buff, data -> u.w.rretval);
			return(reply -> ru.rw.wfd);
			break;
		case 4 :
			reply -> ru.rl.rfd = lseek(data -> u.l.rfd, data -> u.l.offset, data -> u.l.whence);
			return(reply -> ru.rl.rfd);
		case 5 : 
			reply -> ru.rc.wfd = close(data -> u.c.wfd);
			return(reply -> ru.rc.wfd);
			break;

		default : printf("wrong value\n");
				  break;
	}
}

