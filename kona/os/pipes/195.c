#include <stdio.h>
#include <stdlib.h>
#define MSGSIZE 16
main()
{
	char *msg1="hello,world#1";
	char *msg2="hello,world#2";
	char *msg3="hello,world#3";
	char inbuf[MSGSIZE];
	int p[2],j;
	pipe(p);
	write(p[1],msg1,MSGSIZE);
	write(p[1],msg2,MSGSIZE);
	write(p[1],msg3,MSGSIZE);
	for(j=0;j<3;j++)
	{
		read(p[0],inbuf,MSGSIZE);
		printf("%s\n",inbuf);
	}
	exit(0);
}
