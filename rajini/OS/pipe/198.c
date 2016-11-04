#include <stdio.h>
#define MSGSIZE 16
main()
{
	char *m1="hello,world";
	char inbuf[MSGSIZE];
	int p[2],pid,j;
	pipe(p);
	pid = fork();
	if(pid > 0)
	{
		write(p[1], m1, MSGSIZE);
	}
	else 
	{
		write(p[1], m1, MSGSIZE);
		for(j=0;j<=11;j++)
		{
			read(p[0],inbuf,MSGSIZE);
			printf("%s\n",inbuf);
		}
	}
}
