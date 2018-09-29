#include<stdio.h>
main()
{
	int a=10,i;
	for(i=0;a;i++)
		a=a&a-1;
	printf("%d",i);
}


