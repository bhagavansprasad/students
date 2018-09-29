#include <stdio.h>
main()
{
	int pid;
	pid=fork();

	if(pid==0)
	{
		printf("i am the child,my process ID is %d\n",getpid());
		printf("the child's parent process ID %d\n",getppid());
		sleep(20);
		printf("i am the child,my process ID is %d\n",getpid());
		printf("the child's parent process ID %d\n",getppid());
	}
	else
	{
	    sleep(10);
		printf("i am the parent,my process ID is %d\n",getpid());
		printf("the parents's parent process ID %d\n",getppid());
	    printf("Parent terminates\n");
	}

}
