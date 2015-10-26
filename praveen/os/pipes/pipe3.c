#include<stdio.h>
#include<stdlib.h>
#define MSGSIZE 16
main()
{
	char *msg1 = "hello,world";
	char inbuff[MSGSIZE];
	int p[2],pid;
	pipe(p);
	pid = fork();
	if(pid > 0)
	{
		write(p[1],msg1,MSGSIZE);
		//printf("in the child\t");
	}
	else
	{
		sleep(1);
		read(p[0],inbuff,MSGSIZE);
		//printf("in the parent\t");
		printf("%s\n",inbuff);	
	}
	exit(0);
}
