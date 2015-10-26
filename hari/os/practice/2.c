#include<stdio.h>
main()
{

	int a=10;
	printf("process id is %d\n",getpid());
	while(1)
	{
		a++;
		printf("%d\n",a);
		sleep(2);
	}
}	

