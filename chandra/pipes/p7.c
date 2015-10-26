#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16
main()
{
	char *msg1 = " hello,world#1";
	char inbuf[MSGSIZE];
	int p[2], pid;
	pipe(p);

	pid = fork();
	if(pid > 0)
	{
		close(p[0]);
		write(p[1],msg1, MSGSIZE);
	}
	if(pid == 0)
	{
		close(p[1]);
		read(p[0], inbuf, MSGSIZE);
		printf("%s\n", inbuf);

	}
	exit(0);
}
