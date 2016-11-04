#include <stdio.h>
#include <fcntl.h>
#define MSGSIZE 16
main()
{
	char *m1 = "hello world";
	char inbuf[MSGSIZE];
	int p[2],pid,j;
	pipe(p);
	pid = fork();
	if(pid > 0)
	{
		write(p[1],m1,MSGSIZE);
	}
	else
	{
		printf("%d\n",lseek(p[0],0l,2));
		read(p[0],inbuf,MSGSIZE);
		printf("%s\n",inbuf);
	}
}
