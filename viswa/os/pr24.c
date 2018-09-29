#include <stdio.h>

main()
{
	int pid , dip;
	pid = fork();
	if( pid == 0)
	{
		printf("1st child process id is%d \n",getpid());
		printf("first-child dead \n");
	}
	else 
	{
		dip = fork();
		if( dip == 0)
		{
			printf("2nd child process id is %d \n ",getpid());
			printf("second-child dead \n");
		}
		else
		{
			sleep(15);
			printf("i am parent and i am  dying \n");
		}
	}
}
