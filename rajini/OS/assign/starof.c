#include <stdio.h>
main()
{
	int pid;
	int a=15;
	while(a)
	{
		pid=fork();
		if(pid==0)
		{ 
			printf("C : my PID %d\n",getpid());
			printf("C : my PPID %d\n",getppid());
			sleep(100);
			exit(1);
		}
		a--;
	}

	sleep(20);

}


