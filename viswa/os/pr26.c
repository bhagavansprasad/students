#include <stdio.h>

main()
{
	int pid , dip;
	pid = fork();
	if(pid == 0)
	{
		printf("1st childs process id  is %d \n",getpid());
		printf("first- child process terminating from memory \n");
	}
	else
	{
		dip = fork();
		if( dip == 0)
		{
			printf("2nd child process id is %d\n",getpid());
			printf("second-child process terminating \n");
		}
		else
		{
			sleep();
			printf("child with pid %d died\n",wait(0));
			printf("child with pid %d died\n",wait(0));
			printf("i am parent\n")
		}
	}
}
