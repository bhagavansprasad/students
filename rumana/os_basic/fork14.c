#include<stdio.h>
main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("i am the chaild my proces id is %d\n",getpid());
		printf("i am the chaild my parent proces id %d\n",getppid());
	}
	else
	{
		printf("im the parent my process id is %d\n",getpid());
		printf("im the parent my parent process id is %d\n",getppid());
	}
}
