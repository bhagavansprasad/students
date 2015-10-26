#include <stdio.h>
#include <fcntl.h>
#define MSGSIZ 63
main()
{
	int fd;
	char msgbuf[MSGSIZ+1];

	if(mknod("myfifo",010666,0)<0)
		perror("myfifo failed\n");
	if((fd = open("myfifo",O_RDWR))<0)
		perror("fifo open failed\n");
	
	for(;;)
	{
		if(read(fd,msgbuf,MSGSIZ+1)>0)
		printf("message received: %s\n",msgbuf);
	}
}
