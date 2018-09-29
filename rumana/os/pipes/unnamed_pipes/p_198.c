#include<stdio.h>
#include<stdlib.h>
#define MSGSIZE 16
main()
{
	char *msg1="hello,world#1";
	char *msg2="hi,world#2";
	char inbuf[MSGSIZE];
	int p[2],j,pid;
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		write(p[1],msg1,MSGSIZE);
	}
	else
	{
		write(p[1],msg2,MSGSIZE);
		for(j=0;j<=1;j++)
		{
			read(p[0],inbuf,MSGSIZE);
			printf("%s\n",inbuf);
		}
	}
	exit(0);
}
