#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 16

main()
{
	char *msg1 = "hello , world #1";
	char *msg2 = "hello , world #2";
	char *msg3 = "hello , world #3";
	char inbuff[MSGSIZE];
	int p[2],j,retv =0;

	pipe(p);
	write(p[1],msg1,MSGSIZE);
	write(p[1],msg2,MSGSIZE);
	write(p[1],msg3,MSGSIZE);

	for( j = 0; j < 3 ; j++)
	{
		retv = read ( p[0], inbuff ,MSGSIZE);
		inbuff[retv ] = '\0';
		printf("%s\n",inbuff);
	}
	exit(0);
}
