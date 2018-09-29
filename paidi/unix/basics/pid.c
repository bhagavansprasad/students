#include <stdio.h>
main()
#if 0
{
	int pid,i=0;
	pid=fork();
	if(pid == 0)
	{
		printf("child processs : hi papa %d\n",getpid());
		sleep(5);
		printf("child processs : bye papa %d\n",getpid());
	}
	else
	{
		printf("parent processs : hai child%d\n",getpid());
		sleep(5);
		printf("parent processs : bye child %d\n",getpid());
	}
}
#endif
#if 0
{  //* if child terminate child parent ID is adopted Id in this prm its 1*//
	int pid,i=0;
	pid=fork();
	if(pid == 0)
	{
		printf("i am CHILD 1, my processs id : %d\n",getpid());
		printf("i am CHILD 1, my parent processs id : %d\n",getppid());
		sleep(20);
		printf("i am CHILD 2, my processs id : %d\n",getpid());
		printf("i am CHILD 2, my parent processs id : %d\n",getppid());
		sleep(2);
		printf("i am CHILD 3, my processs id : %d\n",getpid());
		printf("i am CHILD 3, my parent processs id : %d\n",getppid());
	}
	else
	{
		sleep(15);
		printf("i am the PARENT, my processs id : %d\n",getpid());
		printf("The parents PARENT processs id : %d\n",getppid());
		printf("parent terminates\n");
	}
}	
#endif
