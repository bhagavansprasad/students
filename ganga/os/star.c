#include "stdio.h"

void main()
{
	int i, pid = 0 ;

	for(i = 0 ; i < 3 ; i++)
	{
		pid = fork() ; 

		if(pid == 0)
		{
			break;
		}

		else
		{
			printf("-->pid %d   \n", getpid());
			printf("-->ppid %d  \n", pid);
		}
	}
	sleep(2);
}
