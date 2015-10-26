#include "hfop2.h"

/*open function*/
int aopen(char *fd,int flag,int mode)
{
	int a;
	a=rpc_open(fd,flag,mode);
	return a;
}

/*read function*/
int aread(int fd,char * buff,int len)
{
	int a;
	a=rpc_read(fd,buff,len);
	return a;
}

/*write function*/
int awrite(int wrt,char *buff,int len)
{
	int a;
	a=rpc_write(wrt,buff,len);
//	return a;
}

/*close function*/
int aclose(int fd)
{
	int a;
	a=rpc_close(fd);
//	return a;
}

