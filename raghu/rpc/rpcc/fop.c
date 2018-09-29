#include <stdio.h>
#include <fcntl.h>
#include "rpc_fp.h"
/*open function*/

static int signal=0;
int aopen(char *fn,int flag,int mode)
{
	int fd=0;

#if 0
	check_is_the_fn_is remote or local
	If remote
		send request i.e. call rpc_open
	else 
		call open system call locally
#endif
	if(!(strncmp(fn,"/",1)))
	{
		fd = rpc_open(fn, flag, mode);
		signal=1;
		return fd;
	}
	else
	{
		fd = open(fn, flag, mode);
		return fd;
	}
}

/*read function*/
int aread(int fn, char *buff, int len)
{
	int fr=0;
	printf("signal is : %d\n",signal);
	if(signal==1)
	{
		fr = rpc_read(fn,buff,len);
		return fr;
	}
	else
	{
	
		fr = read(fn,buff,len);
		return fr;
	}
}

/*write function*/
int awrite(int fn,char *buff,int len)
{
	int fw=0;
	
	if(signal==1)
	{
		fw = rpc_write(fn,buff,len);
		return fw;
	}
	else
	{
		fw = write(fn,buff,len);
		return fw;
		
	}
}

/*close function*/
int aclose(int fn)
{
	int fc=0;

	if(signal==1)
	{
		fc = rpc_close(fn);
		return fc;
	}
	else
	{
		fc = close(fn);
		return fc;
		
	}
}
