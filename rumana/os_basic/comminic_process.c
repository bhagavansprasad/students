#include<stdio.h>
#define MSGSIZE 16
main()
{
	char *msg1="hello,world";
	char *msg2="hi,world";
	int p[2],pid;
	char inbuf[MSGSIZE];
	pipe(p);
	pid=fork();
	if(pid>0)
	{
		write(p[1],msg1,MSGSIZE);
		sleep(5);
		read(p[0],inbuf,MSGSIZE);
		printf("parent : %s\n",inbuf);
	}
	else
	{
		read(p[0],inbuf,MSGSIZE);
		printf("chaild  %s\n",inbuf);
		write(p[1],msg2,MSGSIZE);
		sleep(5);
	}
}
