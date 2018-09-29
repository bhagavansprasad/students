#include <stdio.h>
main()
{
	int i,pid;
	pid=fork();
	if(pid==0)
	{
		printf("am in child my PID :%d \t my PPID :%d beforesleep\n",getpid(),getppid());
		sleep(50);
		printf("am in child my PID :%d \t my PPID :%d aftersleep\n",getpid(),getppid());
	}
	else
	{
		sleep(10);
		printf("am in parent my PID :%d \t my PPID :%d aftersleep\n",getpid(),getppid());
	}
}
