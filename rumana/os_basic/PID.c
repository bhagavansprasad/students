#include <stdio.h>
main()
{
	int pid;
	printf("process pid :%d\n",getpid());
	pid=fork();
	if(pid>0)
	{
		printf("child pid :%dparent pid : %d\n",getpid(),getppid());
	}
	else
	{
		printf("%d\n",getpid());
	}
}
