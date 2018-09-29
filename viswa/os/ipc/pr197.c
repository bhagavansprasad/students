#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16


main()
{
	char *msg1 = "hello , world ";
	char inbuff[MSGSIZE];
	int p[2],j,pid;
	pipe(p);

	pid = fork();

	if( pid > 0)
		write(p[1], msg1, MSGSIZE);
	else
	{
		sleep(1);
		read( p[0], inbuff , MSGSIZE);
		printf("%s\n",inbuff);
	}
	exit(0);
}
