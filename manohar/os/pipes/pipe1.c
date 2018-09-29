#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void abc();
main()
{
	int p[2];
	int retval;
	char *buff="hello";
	char inbuf[8];
	pipe(p);
	signal(SIGPIPE,abc);
	if(fork() == 0)
	{
		//	close(p[0]);
		//	close(p[1]);
		//	sleep(5);
		printf("child exiting\n");
	}
	else
	{
			close(p[0]);
		retval = write(p[1],buff,8);
		printf("value--->%d\n",retval);
		printf("parent exiting\n");
	}
}
void abc()
{
printf("parent is failed\n");
}

