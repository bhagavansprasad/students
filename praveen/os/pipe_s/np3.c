#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

main()
{
	int fd,pid;
	char *msg1="hi";
	char *msg2="hello";
	char inbuff[10];
	fd = open("mypipe",O_RDWR);
	pid = fork();
	if(pid == 0)
	{
		write(fd,msg1,10);
		sleep(1);
		read(fd,inbuff,10);
		printf("the parent value is %s\n",inbuff);
	}
	else
	{
		read(fd,inbuff,10);
		printf("the child sent message is %s\n",inbuff);
		write(fd,msg2,10);
		sleep(1);
	}
}
