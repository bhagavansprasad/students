#include <stdio.h>
main()
{
	int pid;
		pid=fork();
		if(pid == 0)
		{
			printf("child process\n");
			printf("child process pid id %d\n",getpid());
		}
}
