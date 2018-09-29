#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
main()

	/*      wait waits for a process to finish; sleep sleeps for a certain amount of time   */
#if 0
{
	int i=0,pid;
	printf("Readyy to work\n");
	pid = fork();
	if(pid == 0)
	{
		printf("Child starts \n");
		for(i=0;i<1000;i++)
			printf("%d\t",i);
		printf("Child ends\n");
	}
	else
	{
		wait(5);
		printf("parent process\n");

	}
}
#endif

/* HOW TO MAKE PARENT WAIT FOR MORE THAN ONE CHILD */
{
	int dip,pid;
	printf("Readyy to work\n");
	pid = fork();
	if(pid == 0)
	{
		printf("i am 1st Child my process ID %d\n",getpid());
		printf("i am 1st Child my parent process ID %d\n",getppid());
		printf("1st Child dead\n");
	}
	else
	{
		dip=fork();
		if(dip==0)
		{
			printf("i am 2 nd Child my process ID %d\n",getpid());
			printf("i am 2 nd Child my parent process ID %d\n",getppid());
			printf("2 nd Child dead\n");
		}
		else
		{
			printf("i am the parent process ID %d\n",getpid());
			printf("i am the parent my parent process ID %d\n",getppid());
			sleep(15);
			printf("i am parent and i am dying\n");
		}

	}
}


