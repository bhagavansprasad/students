#include <stdio.h>
#include <fcntl.h>
#define SIZE 63
main()
{
	int fd;
	char msgbuf[SIZE+1];

	if((fd = open("testfile",O_RDWR))<0)
	perror("pipe open failed");
	for(;;)
	{
		if(read(fd,msgbuf,SIZE+1)>0)
		printf("message received : %s\n",msgbuf);
	}
}
