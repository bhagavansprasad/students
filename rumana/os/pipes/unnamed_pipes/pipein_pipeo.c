#include<stdio.h>
#define MSGSIZE 16
main()
{
	char *msg1="hello,world#1";
	char *msg2="hello,world#2";
	char *msg3="hello,world#3";
	int p[2],i;
	char inbuf[MSGSIZE];
	pipe(p);
	write(p[1],msg1,MSGSIZE);
	write(p[1],msg2,MSGSIZE);
	write(p[1],msg3,MSGSIZE);
	for(i=0;i<3;i++)
	{
		read(p[0],inbuf,MSGSIZE);
		printf("%s \n ",inbuf);
	}
}
