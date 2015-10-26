#include "struct.h"
#include <string.h>
#include "rpc_fop.h"
#include "second_struct.h"
int client_read( struct school *sch );

int rpc_open(char *file ,int mode , int flag)
{
	int retval;
	struct students student;
	struct school sch ;
	strcpy(student.comb.open.file , file);
	printf("in rpcc file name is :%s\n",student.comb.open.file);
	student.comb.open.mode = mode;
	student.comb.open.flag = flag;
	student.op=1;
	retval = rpc_fop(&student);
	client_read( &sch );
	printf("in rpcc fd  is : %d\n", sch.fun.open.fd);
	return sch.fun.open.fd;
}
int rpc_read(int fd, char *buff , int len)
{
	int retval = 0;
	struct students student;
	struct school sch ;
	student.comb.read.fd = fd;
	student.comb.read.len = len;
	student.op=2;
	retval = rpc_fop(&student);
	client_read( &sch );
	strcpy(buff , sch.fun.read.buff);
	buff[sch.fun.read.fd] = '\0';
	printf("rpcc buff is : %s\n",buff);
	return sch.fun.read.fd;
}

int rpc_write(int fd , char *buff ,int len)
{
	struct students student;
	struct school sch ;
	int retval;
	student.comb.write.fd = fd;
	student.op=3;
	strcpy(student.comb.write.buff ,buff);
	student.comb.write.len = len;
	retval = rpc_fop(&student);
	client_read( &sch );
	return retval;
}

int rpc_close(int fd)
{
	struct students student;
	struct school sch ;
	int retval;
	student.op=4;
	student.comb.close.fd = fd;
	retval = rpc_fop(&student);
	client_read( &sch );
	return retval;
}

