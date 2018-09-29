#include<sys/types.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include "struct.h"
#include "string.h"
#include "rpcc_send_req.h"
#include "structrep.h"
int client_read_req(struct server *s );
int sdump_data_after_read(struct server *data);
// int erro,err,errw,errc;
int rpcc_open(char*pathname, int flags, int mode)
{
	printf("----In rpcc open----\n");

	struct fds a_fds;

	struct server s;
	int retval = 0;

	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	a_fds.type = 1;
	strcpy(a_fds.a_uns.a_open_d1.pathname, pathname);
	a_fds.a_uns.a_open_d1.flags = flags;
	a_fds.a_uns.a_open_d1.mode = mode;

//	retval = rpcc_send_req(&a_fds);
	rpcc_send_req(&a_fds);
	 client_read_req(&s); 
	 sdump_data_after_read(&s);
	
	 retval=s.a_uns.o.fd;
	 erro=s.a_uns.o.erno;
	printf("-->retval :%d\n", retval);
	return retval;
}

int rpcc_read(int fd,char* buff,int count)
{  printf("----In rpcc read----\n");
	struct fds a_fds;
		struct server s;


	int retval = 0;
	
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	a_fds.type = 2;
	a_fds.a_uns.a_read_d2.fd = fd;
	a_fds.a_uns.a_read_d2.count = count;
	//retval =  rpcc_send_req(&a_fds);
	//strncpy(buff,a_fds.a_uns.a_read_d2.buff, retval);
 	rpcc_send_req(&a_fds);
	client_read_req(&s);
	 sdump_data_after_read(&s);
	  retval=s.a_uns.r.rval;
	strcpy(buff,s.a_uns.r.buff);
	err=s.a_uns.r.erno;
	//retval =  rpcc_send_req(&a_fds);
//	strncpy(buff,a_fds.a_uns.a_read_d2.buff,retval);

//	retval =  rpcc_send_req(&a_fds);
//	strcpy(a_fds.a_uns.a_read_d2.buff,buff);

	printf("-->retval :%d\n", retval);

	return retval;
}

int rpcc_write(int fd, char* buff,int count)
{
	printf("----In rpcc write----\n");

	struct fds a_fds;
		
	struct server s;

	int retval = 0;
	a_fds.type = 3;

	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	a_fds.a_uns.a_write_d3.fd = fd;
	strcpy(a_fds.a_uns.a_write_d3.buff, buff);
	a_fds.a_uns.a_write_d3.count = count;

	//retval = rpcc_send_req(&a_fds);
	 rpcc_send_req(&a_fds);
	 	client_read_req(&s);
		 sdump_data_after_read(&s);
		  retval=s.a_uns.w.rval;
		  errw=s.a_uns.w.erno;
		 printf("-->retval :%d\n", retval);
	return retval;
}

int rpcc_close(int fd)
{
	printf("----In rpcc close----\n");

	struct fds a_fds;
		struct server s;

	int retval = 0;
	a_fds.type = 4;
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	a_fds.a_uns.a_close_d4.fd = fd;

//	retval = rpcc_send_req(&a_fds);
	rpcc_send_req(&a_fds);
		client_read_req(&s);
		 sdump_data_after_read(&s);
	 retval=s.a_uns.c.rval;
	 errc=s.a_uns.c.erno;

	printf("-->retval :%d\n", retval);
	return retval;
}

