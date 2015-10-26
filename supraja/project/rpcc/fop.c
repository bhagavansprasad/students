#include <stdio.h>
#include <fcntl.h>
#include "rpc_fp.h"
/*open function*/

int aopen(char *fn,int flag,int mode)
{
	int fop;
	fop = rpc_open(fn, flag,mode);
	return fop;
}

/*read function*/
int aread(int fd,char *buff,int len)
{
	int fr;
	fr = rpc_read(fd,buff,len);
	return fr;
}

/*write function*/
int awrite(int fd1,char *buff,int fr)
{
	
	return rpc_write(fd1,buff,fr);
//	return fw;
}

/*close function*/
int aclose(int fn)
{
	//int fc;
	return rpc_close(fn);
	//return fc;
}
