#include <stdio.h>
#include <fcntl.h>
#include "rpc_fp.h"
/*open function*/
int aopen(char *fn,int flag,int mode)
{
	int fop=0;
	fop = rpc_open(fn,flag,mode);
	return fop;
}

/*read function*/
int aread(int fn,char *buff,int len)
{
	int fr=0;
	fr = rpc_read(fn,buff,len);
	return fr;
}

/*write function*/
int awrite(int fn,char *buff,int len)
{
	int fw=0;
	fw = rpc_write(fn,buff,len);
	return fw;
}

/*close function*/
int aclose(int fn)
{
	int fc=0;
	fc = rpc_close(fn);
	return fc;
}
