#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 20
main()
{
	int i = 0, j = 0, pid, p[2];
	char *msg1[4] = {"hi", "how are you", "fine whatsup", "bye"}; 
	char *msg2[4] = {"hello", "fine how are you", "nothing", "bye"}; 
	char inbuff[MSGSIZE];
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		while(1)
		{
			write(p[1], msg1[i], 20);
			sleep(1);
			
			read(p[0], inbuff, 20);
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
			read(p[0], inbuff, 20);
			printf("from child %s\n", inbuff);
			
			if(strcmp(inbuff, "bye") == 0)
				break;
			
			write(p[1], msg2[j], 20);
			j++;
			
			sleep(2);
			
		}
	}
}
