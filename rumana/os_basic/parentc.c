#include<stdio.h>
main()
{
	int pid,a=10;
	pid=fork();
	printf("pid value is :%d\n",pid);
	if(pid==0)
	{
		while(1)
		{
			printf("chaild value is %d\n",a);
			a++;
			sleep(2);
		}
	}
	else
	{
		while(1)
		{
			printf("parent value is %d \n",a);
			a++;
			sleep(1);
		}
	}
}

