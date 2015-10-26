#include<stdio.h>
#define MSGSIZE 16

main()
{
	char* masg1 = "hello ,world #1";
	char* masg2 = "hello ,world #2";
	char* masg3 = "hello ,world #3";
	char* masg4 = "hello ,world #4";
	char inbuf[MSGSIZE];
	int p[2], j;

	pipe(p);
	write(p[1],masg1,MSGSIZE);
	write(p[1],masg2,MSGSIZE);
	write(p[1],masg3,MSGSIZE);
	write(p[1],masg4,MSGSIZE);

	for( j = 0; j<4; j++)
	{

		read(p[0], inbuf, MSGSIZE);
		printf("%s\n",inbuf);
	}
}


