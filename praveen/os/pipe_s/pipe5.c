#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16
main()
{
	char *msg1 = "hello,world#1";
	char inbuff[MSGSIZE];
	int pid,p[2],i;
	pipe(p);
	pid = fork();
	if(pid > 0)
	{
		close(p[0]);
		write(p[1],msg1,MSGSIZE);
		printf("the parent = %s\n",msg1);
	}
	else
	{
		read(p[0],inbuff,MSGSIZE);
		printf("the child = %s\n",inbuff);
		close(p[1]);
		read(p[0],inbuff,MSGSIZE);
		printf("the child = %s\n",inbuff);
	}
	exit(0);
}
