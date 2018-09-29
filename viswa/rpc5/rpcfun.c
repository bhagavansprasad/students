#include "rpcfop.h"
#include "stuct.h"
#include <string.h>
int rpc_open(char *file, int flag, int mode)
{
	struct student stud;
	stud.op=1;
	stud.fin.ope.mode=mode;
	stud.fin.ope.flag=flag;
	strcpy(	stud.fin.ope.file ,file);
	int fd1;
	fd1 = rpc_fop(&stud);
	return fd1;
}


int rpc_read( int file, char *buff, int len)
{
	struct student stud;
	stud.op=2;
	stud.fin.rea.fd=file;
	strcpy(stud.fin.rea.buff ,buff);
	stud.fin.rea.len=len;
	int fd;
	fd=rpc_fop(&stud);
	strcpy(buff,stud.fin.rea.buff);
	return fd;
}


int rpc_write( int file, char *buff, int len)
{
	struct student stud;
	stud.op=3;
	stud.fin.wri.fd=file;
	strcpy(stud.fin.wri.buff, buff);
	stud.fin.wri.len=len;
	return rpc_fop(&stud);
}


int rpc_close(int file)
{
	struct student stud;
	stud.op=4;
	stud.fin.clo.fd=file;
	return rpc_fop( &stud);

}

