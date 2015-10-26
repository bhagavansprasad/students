#include <stdio.h>
#include <signal.h>
main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{ 

		printf("iam in child\n");
     kill(getppid(),SIGSTOP);
	 sleep(2);
     kill(getppid(),SIGCONT);

	 }
	else
	{

		printf("iam in parent1\n");
		sleep(2);
		printf("iam in parent2\n");


	}
}
