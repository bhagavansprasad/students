#include <stdio.h>
#include <signal.h>

void abc();

main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
		signal(SIGINT,abc);
		sleep(2);
	}
	else
	{
		kill(pid,SIGINT);
		sleep(5);
		printf("parent exiting\n");
	}
}

void abc()
{
	printf("signal is received by the chld\n");
}
