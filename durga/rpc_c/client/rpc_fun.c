#include<fcntl.h>
#include <string.h>
#include "structer.h"
#include "server_structer.h"
#include<stdio.h>

int rpcs_fop(struct data *);
void client_requst(void);
int client_read( struct server *);
	struct server s;
	struct data p;

/*rpc_open function*/
int rpc_open(char *pathname, int mode, int flag)
{
	printf("before call flags : %d\n",flag);
	printf("before call mode : %d\n",mode);
	int  fd1; 
	int retval = -1;
	p.op = 1;
	strcpy(p.t.open.filename,pathname);
	p.t.open.mode = mode;
	p.t.open.flag = flag;
	printf("in rpc fun file name : %s\n",p.t.open.filename);
	printf("in rpc fun flags : %d\n",p.t.open.flag);
	printf("in rpc fun mode : %d\n",p.t.open.mode);
	fd1 = rpcs_fop(&p);
	retval = client_read( &s );
	printf("----->rpc client return retval : %d\n",retval); 
	printf("----->in rpc fd return retval : %d\n",s.u.os.fd); 
	return(s.u.os.fd);
}
/*rpc_read function*/

int rpc_read(int fd, char *buf,int len)
{

	int r;
	int retval;
	p.op = 2;

	p.t.read.fd = fd;
	strcpy(p.t.read.buff, buf);
	p.t.read.len = len;

	r = rpcs_fop(&p);
//	printf("------->read valu r : %d\n", r);
	retval =  client_read( &s);
	strcpy(buf, p.t.read.buff);
	buf[ s.u.rs.r] = '\0';
	printf("------>in rpcc buf is :%s\n",buf);
	return (s.u.rs.r);

}

/*rpc_write function*/

int rpc_write(int fd, char *buf, int len)
{
	int retval;
	int w;
	p.op = 3;

	p.t.write.fd = fd;
	strcpy(p.t.write.buff,buf);
	p.t.write.len = len;

	w = rpcs_fop(&p);
	 client_read( &s);
	return (s.u.ws.w);

}

/*rpc_close function*/

int rpc_close(int fd)
{
	int fd1;
	int retval;
	p.op = 4;

	p.t.close.fd = fd;

	fd1 = rpcs_fop(&p);

	retval = client_read( &s);
	return (s.u.cs.fd);
}
#if 0
/*function for lseek*/
int rpc_lseek( int fd, int offset, int whence)
{
	int l;
	d.op = 5;
	d.t.ls.fd = fd;
	d.t.ls.offset = offset;
	d.t.ls.whence = whence;

	l =	rpcs_fop(&d);
	return (client_read( &s));

}
#endif
