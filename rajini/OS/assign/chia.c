#include <stdio.h>
main()
{
	int pid;
	int a=15;
	while(a)
	{
		pid=fork();
		if(pid!=0)
		{ 
			printf("P : my PID %d\n",getpid());
			printf("P : my PPID %d\n",getppid());
			sleep(100);
			exit(1);
		}
		a--;
	}

}


