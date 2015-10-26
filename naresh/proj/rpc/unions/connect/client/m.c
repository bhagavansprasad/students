#include "stdio.h"
#include "fcntl.h"
#include "defs.h"
#include "fop.h"
#include "arpc.h"
#include "head.h"

int main()
{
	
	int port = 7777;
	char srvr_ip[] = "127.0.0.1";
	int fd = -1;
	init_net_comm(port, srvr_ip);
//	char buff[100];
//	int fd1, rd, w, l;
	
	fd = aopen("t.txt", O_RDONLY, 0);
	printf("--> fd is : %d\n",fd);
/*	fd1 = aopen("n.txt", O_RDWR|O_CREAT, 0777);
	printf("in main fd1 is : %d\n",fd1);

	rd = aread(fd, buff, MAX);

	
	buff[rd] = '\0';


	w = awrite(fd1, buff, rd);
	printf("--->After w :%d\n", w);

	l = alseek(fd, -10l, 2);
	printf("-->after lseek:%d\n",l);

	rd = aread(fd, buff, MAX);
	buff[rd] = '\0';

	printf("-->After read :%d\n", rd);
	printf("-->After read buff   :%s\n", buff);

	w = awrite(fd1, buff, rd);
	printf("--->After write :%d\n", w);

	aclose(fd);
	aclose(fd1);*/
return 0;
}

