#include<stdio.h>
main()
{
	int a=10,n;
	n=fork();
	if(n==0)
	{
		printf("chaild pid value is %d\n",getpid());
		printf("chaild ppid value is %d\n",getppid());
	}
	else
	{
		printf("parent pid value is %d\n",getpid());
		printf("parent ppid value is %d\n",getppid());
		printf("a value is %d\n",a);
	}
}

