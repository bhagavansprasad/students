#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "structure.h"

int process_client_request(fop_data_req *creq, fop_data_rep *sreplay)
{
	
	if(creq->ope == OPEN_REQUEST)
	{
		int fd = 0;
		printf("----> server: OPEN OPERATION\n");
		fd = open(creq->t.op.pathname, creq->t.op.mode, creq->t.op.flags);
		sreplay->ope = OPEN_REPLAY;
		sreplay->u.open.fd = fd;
		printf(" server open fd  = %d\n",sreplay->u.open.fd);

		if(fd < 0 )
		{
			sreplay->u.open.error = errno;
			printf(" server open errno = %d\n",sreplay->u.open.error);
			return sreplay->u.open.error;
		}
		else
			return sreplay->u.open.fd;
	}    
	else if(creq->ope == READ_REQUEST)
	{
		int r = 0;  
printf("----> server: READ OPERATION\n");
		r = read(creq->t.rd.fd, creq->t.rd.buf, creq->t.rd.count);
		sreplay->ope = READ_REPLAY;
		sreplay->u.read.rretval = r;
		creq->t.rd.buf[sreplay->u.read.rretval] = '\0';
			strcpy(sreplay->u.read.buf, creq->t.rd.buf);
		printf("server read retval    = %d\n",sreplay->u.read.rretval);
		printf("server side buff is   = %s\n",sreplay->u.read.buf);
		if(sreplay->u.read.rretval <0)
		{
			sreplay->u.read.error = errno;
			printf("server read errno = %d\n",sreplay->u.read.error);
			return sreplay->u.read.error;
		}
		else
			return sreplay->u.read.rretval;

	}
	else if(creq->ope == WRITE_REQUEST)
	{
		int w = 0;
		printf("----> server: WRITE OPERATION\n");
		w=write(creq->t.wr.fd,creq->t.wr.buf,creq->t.wr.count);
		sreplay->u.write.wretval = w;
		printf("server write retval = %d\n",sreplay->u.write.wretval);
		if(sreplay->u.write.wretval < 0)
		{
			sreplay->u.write.error = errno;
			printf("server write errno = %d\n",sreplay->u.write.error);
			return sreplay->u.write.error;
		}
		return sreplay->u.write.wretval;
	}
	else if(creq->ope == LSEEK_REQUEST)
	{
		int q = 0;
		printf("----> server: LSEEK OPERATION\n");
		q=lseek(creq->t.sk.fd,creq->t.sk.offset,creq->t.sk.whence);
		sreplay->u.lseek.offset = q;
		printf("server lseek retval = %d\n",sreplay->u.lseek.offset);
		if(sreplay->u.lseek.offset < 0)
		{
			sreplay->u.lseek.error = errno;
			printf("server lseek retval = %d\n",sreplay->u.lseek.error);
			return sreplay->u.lseek.error;
		}
		return sreplay->u.lseek.offset;

	}
	else if(creq->ope == CLOSE_REQUEST)
	{
		int c = 0;
		printf("----> server: CLOSE OPERATION\n");
		c=close(creq->t.cls.fd);
		sreplay->u.close.fd = c;
		printf("server close retval = %d\n",sreplay->u.close.fd );
		if(sreplay->u.close.fd < 0)
		{
			sreplay->u.close.error = errno;
			printf("server close errno = %d\n",sreplay->u.close.error);
			return sreplay->u.close.error; 
		}

		return sreplay->u.close.fd;
	}

	return 0;
}

