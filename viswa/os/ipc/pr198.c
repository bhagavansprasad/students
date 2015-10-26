#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16


main()
{
	char *msg1 = "hello , world #1";
	char *msg2 = "hello , world #2";
	char inbuff[MSGSIZE];
	int p[2],j,pid,retv;
	
	pipe(p);
	pid = fork();

	if(pid == 0)
		write (p[1] , msg2 , MSGSIZE);
	else
	{	
		//wait(0);
		write(p[1] , msg1 , MSGSIZE);
		for( j = 0 ; j<=1 ;j++)
		{
			retv = read (p[0], inbuff , MSGSIZE);
			inbuff[retv] = '\0';
			printf("%s \n",inbuff);
		}
	}
	exit(0);
}
