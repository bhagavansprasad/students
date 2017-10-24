#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "crpc.h"

//open 1.txt in read mode
//open 2.txt in write mode
//read first 10 bytes from 1.txt
//write 10 bytes to 2.txt
//read last 10 bytes from 1.txt
//write 10 bytes to 2.txt
//close 1.txt
//close 2.txt

char srvr_addr[] = "127.0.0.1";
int srvr_port = 9090;

int main()
{
	int fd1 = 0, fd2 = 0, rd = 0, ld = 0, wd = 0;
	char buff[256];

	init_client_connection(srvr_addr, srvr_port);

	fd1 = crpc_open("t.txt", O_RDONLY, 0744);
	printf("-->C: fd1 :%d\n\n", fd1);

	fd2 = crpc_open("s.txt", O_CREAT | O_WRONLY, 0744);
	printf("-->C: fd2 :%d\n\n", fd2);

	rd = crpc_read(fd1, buff, 10);
	printf("-->C: crpc_read retval :%d\n", rd);
	rd[buff]='\0';
	printf("-->C: buff :%s\n\n ", buff);

	wd = crpc_write(fd2, buff, 10);
	printf("wd :%d\n\n", wd);
	printf("buff :%s\n\n ", buff);

	ld = crpc_lseek(fd1, -10, SEEK_END); 
	printf("ld :%d\n\n ", ld);

	rd = crpc_read(fd1, buff, 10);
	printf("rd :%d\n\n", rd);
	rd[buff]='\0';
	printf("buff :%s\n ",buff);

	wd = crpc_write(fd2, buff, 10); 
	printf("wd :%d\n\n", wd);
	printf("buff :%s\n ", buff);

	crpc_close(fd1);
	printf("fd1 :%d\n\n", fd1);

	crpc_close(fd2);
	printf("fd2 :%d\n\n", fd2);

	return 0;
}
