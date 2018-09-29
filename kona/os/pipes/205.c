#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void abc();
main()
{
	int p[2],pid,retval;
	char buff[10];
	pipe(p);
	signal(SIGPIPE,abc);
	pid=fork();
	if(pid == 0)
	{
		printf("child process is exiting\n");
	}
	else
	{
		close(p[0]);
		retval=write(p[1],buff,1);
		printf("retuned val is :%d\n",retval);
		printf("parent is exiting\n");
	}
}
void abc()
{
	printf("parent fallied\n");
}
