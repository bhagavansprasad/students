#include <stdio.h>
#include <signal.h>

void abc();
int pid,i;

main()
{
	pid = fork();
	if(pid == 0)
	sleep(1);
	else
	{
		sleep(1);
		signal(SIGCLD,abc);
		for(i=0;i<1000;i++)
			printf("%d..\t",i);
		printf("\n parent exit\n");
	}
}

void abc()
{
	printf("\n I is %d\n",i);
	printf("child died \n");
	getchar();
}
