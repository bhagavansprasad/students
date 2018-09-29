#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16
main()
{
	char *msg1 = "hello,world#1";
	char inbuff[MSGSIZE];
	int p[2], j, pid;
	pipe(p);
	pid = fork();
	if(pid > 0)
	{
		write(p[1], msg1, MSGSIZE);

	}
	else
	{
		printf("%d\n", lseek(p[0], 2l,2));
		read(p[0], inbuff, MSGSIZE);
		printf("buff is : %s\n", inbuff);
	}
	exit(0);
}
