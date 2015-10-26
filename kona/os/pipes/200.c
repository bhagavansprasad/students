#include <stdio.h>
main()
{
	char *buff="hello";
	int p[2],pid,retval;
	char inbuf[5];
	pipe(p);
	pid=fork();
	if(pid==0)
	{
		close(p[1]);
		sleep(5);
		printf("child is exiting\n");
	}
	else
	{
		close(p[1]);
		retval=read(p[0],inbuf,5);
		printf("val returned is :%d\n",retval);
	}
}
