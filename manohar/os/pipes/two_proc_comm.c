#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16
main()
{
	char *msg1="helloworld";
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
		printf("%s\n",inbuf);
	}
	exit(0);
}
