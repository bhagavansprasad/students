#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16


main()
{
	char *msg1 = "hello , world #1";
	char inbuff[MSGSIZE];
	int p[2],j,pid,retv = 0;

	pipe(p);
	pid = fork();

	if( pid > 0)
	{
		write( p[1] , msg1 , MSGSIZE);
	}
	else
	{
		printf("%d \n", lseek(p[0],0L,2));
		retv = read( p[0] , inbuff , MSGSIZE);
		inbuff[retv ] = '\0';
		printf("%s \n",inbuff);
	}
	exit(0);
}
