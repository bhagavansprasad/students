#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16
int main()
{
	char *msg1="hello,world #1";
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
		read(p[0],inbuf,MSGSIZE);
		printf("first print value:%s\n",inbuf);
		read(p[0],inbuf,MSGSIZE);
		printf("next print value:%s\n",inbuf);
	}
	exit(0);
}
