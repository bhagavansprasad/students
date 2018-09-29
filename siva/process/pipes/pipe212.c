#include<fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#define msgsize 16
main()
{
	int p[2],i,pid;
	char *msg="HELLO WORLD #1";
	char inbuff[msgsize];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
	write(p[1],msg,msgsize);
	}
	else
	{
	printf("%d\n",lseek(p[0],0,2));
	read(p[0],inbuff,msgsize);
	printf("%s\n",inbuff);
	}
	exit(0);
}
