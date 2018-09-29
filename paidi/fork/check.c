/*how to make parent wait for more than one child*/
#include <stdio.h>
main()
{
	int pid,dip;
	pid=fork();
	if(pid==0)
	{
		printf("1st child's process ID is %d\n",getpid());
		printf("fist-child dead\n");
	}
	else
	{
		dip=fork();
		if(dip==0)
		{
			printf("2nd child process ID is %d\n",getpid());
			printf("second child dead\n");
		}
		else
		{
			sleep(15);
			printf("i am parent and i am dying\n");
		}
	}
}
