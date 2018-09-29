#include <stdio.h>
main()
{
	int pid;
	int a=2;
	while(a)
	{
		pid=fork();
		if(pid==0)
		{ 
			printf("C : my PID %d\n",getpid());
			printf("C : my PPID %d\n",getppid());
			sleep(4);
		}
		else
		{
			printf("P : my PID %d\n",getpid());
			printf("P : my PPID %d\n",getppid());
			sleep(4);
         }
		 
		a--;
	}

}


