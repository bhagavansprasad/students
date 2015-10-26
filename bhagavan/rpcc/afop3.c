#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
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

int a_read(int fd, char* buff, int count)
{
	int retval = 0;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

	printf("-->fd :%d, count :%d\n", fd, count);

	retval = rpcc_read(fd, buff, count);	
	buff[retval]='\0';
	printf("-->retval :%d\n", retval);
	printf("-->buff   :%s\n", buff);

	return retval;
}

int a_write(int fd2, char* buff,int count)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	return rpcc_write(fd2,buff,count);
}

int a_close(int fd)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	return rpcc_close(fd);
}

