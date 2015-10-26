#include <fcntl.h>

/*open funtion*/
int rpc_open(char *fd,int flag,int mode)
{
	int b;
	b= open(fd,flag,mode);
	return b;
}

/*read funtion*/
int rpc_read(int fd,char *buff,int len)
{
	int b;
	b= read(fd,buff,len);
	return b;
}

/*write funtion*/
int rpc_write(int wrt,char *buff,int len)
{
	int b;:exe "!" . g:ctags_command

	b= write(wrt,buff,len);
	//	return b;
}

/*close funtion*/
int rpc_close(int fd)
{
	int b;
	b=close(fd);
	//	return b;
}
