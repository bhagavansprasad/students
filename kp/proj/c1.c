/*
   C ECHO client example using sockets
 */
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
#include "define.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FILE_OPEN 1
#define FILE_READ 2
#define FILE_WRITE 3
#define FILE_SEEK 4
#define FILE_CLOSE 5
int fd;

int main(int argc , char *argv[])
{
	int read_retval, write_retval, rfd, wfd, pos, sock;
	char buf[100];
	char rfname[10];
	char wfname[10];
	init_sock(sock);	

 /* printf("%s\n",argv[1]);
	strcpy(wfname, argv[1]);
	strcpy(rfname, argv[2]);

	printf("-->rfname :%s\n", rfname);
	printf("-->wfname :%s\n", wfname);
*/
	rfd = aura_openc("1.txt", O_RDONLY);
	wfd = aura_openc("2.txt", O_WRONLY);

	read_retval = aura_readc(rfd, buf, 10);
	buf[read_retval]='\0';
	write_retval = aura_writec(wfd, buf, read_retval);

	pos = aura_lseekc(rfd, -20, SEEK_END);
	pos = aura_lseekc(rfd, pos, SEEK_SET);

	read_retval = aura_readc(rfd, buf, 20);
	buf[read_retval]='\0';

	write_retval = aura_writec(wfd, buf, read_retval);

	aura_closec(rfd);
	aura_closec(wfd);
close(sock);
return 0;
}

int aura_openc(char *fname, int flags)
{
	fop_data datac;

	datac.cmd = FILE_OPEN;
	strcpy(datac.udata.opn.fname, fname);
	datac.udata.opn.mode = flags;
	send_sock_req(&datac);
	printf("__LINE__");
	//recv_sock_data()
	return datac.udata.opn.fd;

}

int aura_readc(int fd, char *buf, int count)
{
	fop_data datac;

	datac.cmd = FILE_READ;
	datac.udata.rdwt.fd = fd;
	datac.udata.rdwt.count = count;
	strncpy(buf, datac.udata.rdwt.buffer, datac.udata.rdwt.count);

	//return datac.udata.rdwt.count;


}

int aura_writec(int fd, char *buf, int count)
{
	fop_data datac;

	datac.cmd = FILE_WRITE;
	datac.udata.rdwt.fd=fd;
	strncpy(buf,datac.udata.rdwt.buffer, datac.udata.rdwt.count);
	datac.udata.rdwt.count=count;


	//return datac.udata.rdwt.count;
}

int aura_lseekc(int fd, off_t offset, int whence)
{
	fop_data datac;

	datac.cmd = FILE_SEEK;
	datac.udata.seek.fd=fd;
	datac.udata.seek.offset=offset;
	datac.udata.seek.whence=whence;


	//return datac.udata.seek.offset;
}

int aura_closec(int fd)
{
	fop_data datac;

	datac.cmd=FILE_CLOSE;
	datac.udata.cls.fd=fd;

	
}




