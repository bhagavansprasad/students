#include<stdio.h>
main()
{
	int pid,i;
	printf("parent is %d\n",getppid());
	for(i=0;i<=4;i++)

       {
		pid=fork();
		if(pid>0)
		{
			printf("parent is %d chaild is %d\n",getppid(),getpid());
		}
		else
		{
			sleep(5);
		}
	}
}
