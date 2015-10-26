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
		printf("%d\n",lseek(p[0],0L,2));
		read(p[0],inbuf,MSGSIZE);
		printf("%s\n",inbuf);
	}
	exit(0);
}
