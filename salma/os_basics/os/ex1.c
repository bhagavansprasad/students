#include<stdio.h>
main()
{
	int a=10,i;
	printf("%p  \n",&a);
	for(i=0;i<20;i++)
	{
		printf("%d \n",a);
		sleep(20);
	}
}
