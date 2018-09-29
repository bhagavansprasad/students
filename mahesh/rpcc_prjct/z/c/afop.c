#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "rpcc.h"

int a_open( char*pathname,int flags,int mode)
{
	int retval = 0;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("-->pathname :%s, flags :%d, mode :%d\n", pathname, flags, mode);


	retval = rpcc_open(pathname,flags, mode);

	printf("-->retval :%d\n", retval);

	return retval;
}

int a_read(int fd, void* buff, int count)
{
	int retval = 0;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("-->fd :%d, count :%d\n", fd, count);

	retval = rpcc_read(fd, buff, count);	

	printf("-->retval :%d\n", retval);
	printf("-->buff   :%s\n", buff);

	return retval;
}

int a_write(int fd, void* buff,int count)
{
	int retval = 0;	
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	
	printf("-->fd :%d, count :%d\n", fd,count);
	
retval = rpcc_write(fd,buff,count);
	
	printf("-->retval :%d\n", retval);
	printf("-->buff   :%s\n", buff);

	return retval;
}

int a_close(int fd)
{
	int retval = 0;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("-->fd :%d\n", fd);
	
	retval = rpcc_close(fd);
	printf("-->retval :%d\n",retval);
	
	return retval;
}

