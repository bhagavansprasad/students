#include "struct.h"
#include <string.h>
#include "afun2.h"
int rpc_open(char *file ,int mode , int flag)
{
	struct students student;
	strcpy(student.comb.open.file , file);
	student.comb.open.mode = mode;
	student.comb.open.flag = flag;
	student.op=1;
	return rpc_fop(&student);
}

int rpc_read(int fd, char *buff , int len)
{
	int retval;
	struct students student;
	student.comb.read.fd = fd;
	strcpy(student.comb.read.buff ,buff);
	student.comb.read.len = len;
	student.op=2;
	retval = rpc_fop(&student);
	strcpy(buff , student.comb.read.buff);
	return retval;
}

int rpc_write(int fd , char *buff ,int len)
{
	struct students student;
	student.comb.write.fd = fd;
	student.op=3;
	strcpy(student.comb.write.buff ,buff);
	student.comb.write.len = len;
	return rpc_fop(&student);
}

int rpc_close(int fd)
{
	struct students student;
	student.op=4;
	student.comb.close.fd = fd;
	return rpc_fop(&student);
}

