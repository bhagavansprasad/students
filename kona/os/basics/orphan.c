#include <stdio.h>
main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("child process ID is :%d\n",getpid());
		printf("child parent  process ID is :%d\n",getppid());
		sleep(10);
		printf("child process ID is :%d\n",getpid());
		printf("child parent  process ID is :%d\n",getppid());
	}
	else
	{
		//sleep(10);
		printf(" parent  process ID is :%d\n",getpid());
		printf("parents parent  process ID is :%d\n",getppid());
     	//printf("parent terminates\n");
	 }


}
