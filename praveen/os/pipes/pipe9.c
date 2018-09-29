#include<stdio.h>
#include<fcntl.h>
#define MSGSIZE 16
//char *msg2 = "bye";
main()
{
	char *msg1 = "hello";
	int p[2],pid;
	char inbuff[10];
	pipe(p);
	pid = fork();
	if(pid == 0)
	{
		printf("--->child<----\n");
		read(p[0],inbuff,10);
		printf("the child is = %s\n",inbuff);
	}
	else
	{
		printf("--->parent<---\n");
		write(p[1],msg1,10);
		printf("the parent is = %s\n",msg1);
	}
}
