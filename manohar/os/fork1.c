#include <stdio.h>
main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
		printf("iam the child my pid is %d\n",getpid());
		printf("iam the parent my pid is %d\n",getpid());
	}
	else
	{
		printf("iam the parent my pid is %d\n",getpid());
		printf("iam the parents parent my pid is %d\n",getpid());
	}
}

