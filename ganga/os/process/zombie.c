#include <stdio.h>
#include <stdlib.h>

main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
		exit(0);
	}
	else
		printf("parent process id is %d\n", getppid());
}
