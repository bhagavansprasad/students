#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include "req_defs.h"
#include "string.h"
#include "rpcc_send_req.h"

int rpcc_open(char*pathname, int flag, int mode)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

	struct fds a_fds;

	a_fds.type=1;
	strcpy(a_fds.a_uns.a_open_d1.pathname, pathname);
	a_fds.a_uns.a_open_d1.flag = flag;
	a_fds.a_uns.a_open_d1.mode = mode;

	return rpcc_send_req(&a_fds);
}

int rpcc_read(int fd1,char* buff,int count)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

	struct fds a_fds;
	int retval = 0;

	a_fds.type=2;
	a_fds.a_uns.a_read_d2.fd1=fd1;
	//a_fds.a_uns.a_read_d2.buff=buff;
	a_fds.a_uns.a_read_d2.count=count;

	retval =  rpcc_send_req(&a_fds);
	strncpy(buff,a_fds.a_uns.a_read_d2.buff,retval);
	buff[retval]='\0';
	printf("rtval-->%d\n. buff:%s\n count:%d\n", retval, buff,count);

	return retval;
}

int rpcc_write(int fd2, char* buff,int count)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	int retval = 0;



	struct fds a_fds;
	a_fds.type=3;
	a_fds.a_uns.a_write_d3.fd2=fd2;
	strcpy(a_fds.a_uns.a_write_d3.buff, buff);
	a_fds.a_uns.a_write_d3.count=count;
		retval= rpcc_send_req(&a_fds);
		

	printf("fd2->%d\n. buff:%s\n count:%d\n", fd2, buff,count);

	return retval;
}




int rpcc_close(int fd)
{
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	int retval = 0;



	struct fds a_fds;
	a_fds.type=4;
	a_fds.a_uns.a_close_d4.fd=fd;
			retval= rpcc_send_req(&a_fds);

	printf("fd->%d\n. retval:%d\n", fd, retval);

	return retval;
}




