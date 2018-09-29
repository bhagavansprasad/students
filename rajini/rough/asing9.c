#include <stdio.h>
main()
{
	int pid=fork();
	if(pid==0)
	{
		printf("i am child,my process ID is: %d\n",getpid());
		printf("the child's parent process ID is: %d\n",getppid());
		
		sleep(1);

		printf("i am child,my process ID is: %d\n",getpid());
		printf("the child's parent process ID is: %d\n",getppid());
	}
	else
	{
		printf("i am parent,my process ID is:%d\n",getpid());
		printf("the parents parent process ID is:%d\n",getppid());
	}

}
