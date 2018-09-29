#include<stdio.h>
main()
{
<<<<<<< HEAD
	printf("hi");
	fork();
	printf("hello");
=======
	int pid = fork();
	if(pid == 0)
	{
	printf("pid %d\n",pid);
	printf("child pid is %d\n",getpid());
	}
	else
	{
	printf("parent pid is %d\n",getppid());
	}
	printf("hi");
	printf("hell0");
>>>>>>> cf910f9351b12602d46981bd3b7c9eb08fcb4592
}
