#include<stdio.h>
#include<stdlib.h>
#define MSGSIZE 16
main()
{
	char *msg1 = "hello,world#1";
	char inbuff[MSGSIZE];
	int p[2],pid,i;
	pipe(p);
	pid = fork();
	if(pid > 0)
	{
	write(p[1],msg1,MSGSIZE);
			printf("parent is:%s\n",msg1);
	}
	else
	{
		write(p[1],msg1,MSGSIZE);
			printf("child is :%s\n",msg1);
		for(i=0;i<=1;i++)
		{
			read(p[0],inbuff,MSGSIZE);
			printf("child is :%s\n",inbuff);
		}
	}exit(0);
	
}
