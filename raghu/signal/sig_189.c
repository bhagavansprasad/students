#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void abc();
int pid,i;
main()
{
	pid = fork();
	if(pid == 0)
	{
		sleep(1);
		kill(getppid(),SIGUSR1);
		exit(0);
	}
	else
	{
		signal(SIGUSR1,abc);
		for(i=0;i<1000;i++)
			printf("%d\n",i);
		printf("parent exiting\n");
	}
}

void abc()
{
	printf("\n I is %d\n",i);
}
