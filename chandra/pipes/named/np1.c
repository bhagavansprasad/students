#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#define MSGSIZE 20
main()
{
	int i = 0, j = 0, pid, fd;
	char *msg1 = "hi"; 
	char *msg2 = "hello"; 
	char *msg3 = "how are you"; 
	char *msg4 = "i am fine"; 
	char inbuff[MSGSIZE];
	fd = open("balu", O_RDWR);
	pid = fork();
	if(pid == 0)
	{
			write(fd, msg3, MSGSIZE);
			write(fd, msg4, MSGSIZE);
			sleep(1);
			read(fd, inbuff, MSGSIZE);
			printf("from parent %s\n", inbuff);
			read(fd, inbuff, MSGSIZE);
			printf("from parent %s\n", inbuff);
			
		
	}
	else
	{
			read(fd, inbuff, MSGSIZE);
			printf("from child %s\n", inbuff);
			read(fd, inbuff, MSGSIZE);
			printf("from child %s\n", inbuff);
			
			
			write(fd, msg1, MSGSIZE);
			write(fd, msg2, MSGSIZE);
			
			sleep(1);
			
		
	}
}
