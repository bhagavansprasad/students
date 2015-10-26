#include <stdio.h>

main()
{
	int pid, dip;
	pid = fork();
	if(pid == 0)
	{
		printf("1st chi;d process id is %d \n",getpid());
		printf("first - chil.d proces terminaTING 		\n");
	}
	else
	{
		dip = fork();
		if(dip == 0)
		{
		printf("2nd chi;d process id is %d \n",getpid());
		printf("second- chil.d proces terminaTING 		\n");
		}
		else
		{
			printf("child with pid %d died \n", wait(0));
			printf("child with pid %d died \n", wait(0));
			printf("i am parent \n");
			sleep();
		}
	}
}
