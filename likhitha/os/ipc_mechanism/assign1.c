#include <stdio.h>

main()
{
	printf("I am forking a child process\n");

	int pid=fork();

	if(pid == 0)
	{
		while(1)
		{
			printf("child process\n");
			printf("%d\n",getpid());
			sleep(4);
		}
	}

	else
	{
		while(1)
		{
			printf("parent process\n");
			printf("%d\n",getppid());
			sleep(2);
		}
	}

}
