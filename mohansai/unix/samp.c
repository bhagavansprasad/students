#include"stdio.h"
main()
{
	int pid;
	pid=fork();

	if(pid==0)
	{
		printf("i am the child my process id is %d\n",getpid());

		printf("the child's parent process id is %d\n",getpid());
	
	sleep(10);
	
		printf("i am the child my process id is %d\n",getpid());
	
		printf("the child's parent process id is %d\n",getpid());
	
	}
	else
	{
		printf("i am the parent my process id is %d\n",getppid());

		printf("the parents parent process id is %d\n",getppid());
	}
}
