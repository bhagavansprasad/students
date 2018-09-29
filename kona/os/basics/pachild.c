#include <stdio.h>
main()
{
	getpid();
	printf("--->process ID is :%d\n",getpid());
	getppid();
	printf("--->proces ID is :%d\n",getppid());
	int a=10;
	if(fork()==0)
	{
		while(1)
		{
			printf("---->a child val is :%d\n",a);
			a++;
			sleep(1);
			printf("---->a  child val is :%d\n",a);
			a++;
			sleep(1);
			printf("---->a child val is :%d\n",a);
			break;
		}
	}
	else
	{
		while(1)
		{
			printf("---->a parent val is :%d\n",a);
			a++;
			sleep(1);
			printf("---->a parent val is :%d\n",a);
			a++;
			sleep(1);
			printf("---->a parent val is :%d\n",a);
			break;

		}
	}
}

