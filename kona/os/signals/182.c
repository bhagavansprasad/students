#include <stdio.h>
#include <signal.h>
void abc();
int pid,i;
main()
{
	pid=fork();
	if(pid == 0)
	sleep(1);
	else
	{
		signal(SIGCLD,abc);
		for(i=0;i<100;i++)
		printf("%d..\t",i);
		printf("parent exiting\n");
	}
}
void abc()
{
	printf("%d\n",i);
	printf("child is died\n");
	getchar();
}
