#include<stdio.h>
//#include<stdlib.h>
int a=10;
main()
{
	int i;
	for(i=1;i<10;i++)
	{
		printf("%d\n",a);
		a++;
		sleep(3);
	}
}
