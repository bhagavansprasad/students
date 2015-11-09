#include<stdio.h>
main()
{
	int pid = fork();
	if(pid == 0)
	{
	printf("pid %d\n",pid);
	printf("child pid is %d\n",getpid());
	}
	else
	{
	printf("parent pid is %d\n",getppid());
	}
	printf("hi");
	printf("hell0");
}
