#include<stdio.h>
main()
{
	int pid,a=10;
	pid=fork();
	/*printf("%d\n",pid);
	//printf("%d\n",pid());
	printf("hello world\n");*/
	if(pid==0)
	{
		while(1)
		{
			printf("in child a :%d\n",a);
			a++;
	//		sleep(1);
		}
	}
	else
	{
		while(1)
		{    
		sleep(2);
			printf("in parent a:%d\n",a);
			a++;
			//printf("%d\n",a);
		//	sleep(1);
		}
	}
}
