#include <stdio.h>
main()
{
	int pid=0;
	pid=fork();
	if(pid==0)
	{
		printf("i am the child pid-->%d\ti am the child ppid-->%d\n ",getpid(),getppid());
	}
	else
	{
		printf("i am the parent pid-->%d\ti am the parent ppid--> %d\n ",getpid(),getppid());
		sleep(1);
		fork();
		if(pid==0)
		{
			printf("i am the child pid-->%d\ti am the child ppid-->%d\n ",getpid(),getppid());
		    sleep(1);
		}
		else
		{
		    sleep(1);
			printf("i am the parent pid-->%d\ti am the parent ppid--> %d\n ",getpid(),getppid());
		} 
	}
}
