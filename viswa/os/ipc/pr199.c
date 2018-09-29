#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16

main()
{
	char *msg1 = "hello , world #1";
	char inbuff[MSGSIZE];
	int retv =0 ,p[2],pid,j;
	
	pipe(p);
	pid = fork();

	if( pid > 0)
	{
		close(p[0]);
		write(p[1], msg1 , MSGSIZE);
	}
	if( pid == 0)
	{
		close(p[1]);
		retv = read(p[0] ,inbuff , MSGSIZE);
		inbuff[retv] = '\0';
		printf("%s\n", inbuff);
	}
	exit(0);
}
