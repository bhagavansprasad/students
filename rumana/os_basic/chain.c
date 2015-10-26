#include<stdio.h>
#include<stdlib.h>
main()
{
	int pid,i;
//	printf("pid is %d\n",getpid());
	for(i=0;i<=10;i++)
	{
		pid=fork();
		if(pid==0)
		{
			printf("parent is %d chaild is %d\n",getppid(),getpid());
		}
		else
		{
		sleep(5);
		exit(1);
		}
	}
}
