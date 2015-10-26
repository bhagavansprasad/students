#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>	
#include <stdio.h>
#include "struct.h"
#include "rpcs.h"
#include "structrep.h"
#include "errno.h"
int server_reply_data(struct server *s);

struct server s;
//int errno=0;
int s_open( char*pathname,int flags,int mode)
{
	int retval = 0;
	printf("________opening a file:\n_________");
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("-->pathname :%s, flags :%d, mode :%d\n", pathname, flags, mode);
	retval = open(pathname, flags, mode);
	if(retval<0)
	{	
		printf("------------>errno:%d",errno);
		perror("------------>error is :");
	}
	s.type=1;
	s.a_uns.o.fd=retval;
	s.a_uns.o.erno=errno;

	server_reply_data(&s);


	//open(pathname, flags, mode);

	printf("-->retval :%d\n",retval);
	return retval;
}

int s_read(int fd,char* buff,int count)
{
	printf("__________reading a file:\n__________");
	int retval = 0;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("-->fd :%d, count :%d\n", fd, count);
	retval = read(fd,s.a_uns.r.buff,count);
	if(retval<0)
	{	
		printf("------------>errno:%d",errno);
		perror("------------>error is :");
	}
	s.type=2;
	s.a_uns.r.rval=retval;
	//strcpy(s.a_uns.r.buff,buff);
	s.a_uns.r.erno=errno;
	server_reply_data(&s);

//	printf("-->retval :%d\n", retval);
//	printf("-->buff   :%s\n",s.a_uns.r.buff);
	return retval;
}

int s_write(int fd, char* buff,int count)
{	
	printf("__________writing into a file__________\n");
	int retval = 0;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("-->fd :%d, count :%d\n", fd, count);

	retval = write(fd,buff,count);
	if(retval<0)
	{	
		printf("------------>errno:%d",errno);
		perror("------------>error is :");
	}
	s.type=3;
	s.a_uns.w.rval=retval;
	s.a_uns.w.erno=errno;
	server_reply_data(&s);
	
	printf("-->retval :%d\n", retval);
	printf("-->buff   :%s\n", buff);
	return retval;
}

int s_close(int fd)
{
	printf("____________closing a file__________\n");
	int retval = 0;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("-->fd :%d\n", fd);

	retval = close(fd);
	if(retval<0)
	{	
		printf("------------>errno:%d",errno);
		perror("------------>error is :");
	}
	s.type=4;
	s.a_uns.c.rval=retval;
	s.a_uns.c.erno = errno;
	server_reply_data(&s);
	printf("-->retval :%d\n",retval);

	return retval;
}

