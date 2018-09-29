#include "stdio.h"

void main()
{
	int i, pid = 0 ;
	for(i = 0 ; i < 3 ; i++)
	{
		pid = fork() ; 

		if(pid == 0)
		{
			printf("-->pid %d  \n", getpid());
			printf("-->ppid %d  \n", getppid());
		}

		else
			break ;
	}
	sleep(5);
}
