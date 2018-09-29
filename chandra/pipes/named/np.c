#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#define MSGSIZE 20
main()
{
	int i = 0, j = 0, pid, fd;
	char *msg1[4] = {"hi", "how are you", "fine whatsup", "bye"}; 
	char *msg2[4] = {"hello", "fine how are you", "nothing", "bye"}; 
	char inbuff[MSGSIZE];
	fd = open("balu", O_RDWR);
	pid = fork();
	if(pid == 0)
	{
		while(1)
		{
			write(fd, msg1[i], MSGSIZE);
			sleep(1);
			
			read(fd, inbuff, MSGSIZE);
			printf("from parent %s\n", inbuff);
			
			if(strcmp(inbuff, "bye") == 0)
				break;
			i++;
			sleep(2);
		}
	}
	else
	{
		while(1)
		{
			read(fd, inbuff, MSGSIZE);
			printf("from child %s\n", inbuff);
			
			if(strcmp(inbuff, "bye") == 0)
				break;
			
			write(fd, msg2[j], MSGSIZE);
			j++;
			
			sleep(2);
			
		}
	}
}
