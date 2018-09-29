#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#define MSGSIZ 63
main(argc,argv)
{
	int fd;
	char msgbuf[MSGSIZ+11];
	if(argc < 2)
	{
		printf("failhjfkakjdskjd\n");
		exit(1);
	}
	if((fd = open("testpipe",O_RDWR))<0)
		perror("pipe open failed\n");
	for(;;)
	{
		if(read(fd,msgbuf,MSGSIZ+1)>0)
			printf("message received:%s\n",msgbuf);
	}
}
