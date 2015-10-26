#include <stdio.h>
#define MSGSIZE 16
#include <stdlib.h>
main()
{
	char *msg1 = "hi,world#1";
	char inbuff[MSGSIZE];
	int p[2],j,pid;
	pipe(p);
	pid = fork();
	if(pid > 0)
	{
		write(p[1],msg1,MSGSIZE);
		printf("parent = %s\n",msg1);
	}
	else
	{
		write(p[1],msg1,MSGSIZE);
		printf("child = %s\n",msg1);
		for(j=0;j<2;j++)
		{
			read(p[0],inbuff,MSGSIZE);
			printf("child read value is = %s\n",inbuff);
		}}
}
