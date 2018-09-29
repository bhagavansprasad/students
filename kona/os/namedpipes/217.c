#include <stdio.h>
#include <fcntl.h>
#define MSGSIZ 63
main()
{
	int fd;
	char msgbuf[ MSGSIZ+1];
	if((fd=open("sreenu.txt",O_RDWR))<0)
	perror("pipe open failed\n");
	for(;;)
	{
		if(read(fd,msgbuf,MSGSIZ+1)>0)
		printf("message received :%s\n",msgbuf);
	}
}
