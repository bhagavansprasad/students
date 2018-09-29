#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#define MSGSIZ 63
main(int argc, char *argv[])
{
	int fd,j,nwrite;
	char msgbuf[MSGSIZ];
	if(argc<2)
	{
		printf("usage: ");
		exit(1);
	}
	if((fd=open("myfifo",O_WRONLY))<0)
		perror("fifo open failed\n");
	for(j=1;j<argc;j++)
	{
		strcpy(msgbuf,argv[j]);
		if((nwrite=write(fd,msgbuf,MSGSIZ+1))<=0)
			perror("message write failed\n");
	}
}
