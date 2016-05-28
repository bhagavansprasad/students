#include <stdio.h>
#include <signal.h>
void abc();
main()
{
	int pid,p[2];
	int retval;
	char buff[10];
	pipe(p);
	signal(SIGPIPE,abc);
	pid = fork();
	if(pid == 0)
	{
		printf("child exiting\n");
	}
	else
	{
		close(p[0]);
		retval = write(p[1],buff,1);
		printf("value returned: %d\n",retval);
		printf("parent exiting\n");
	}
}
void abc()
{
	printf("parent failed\n");
}
