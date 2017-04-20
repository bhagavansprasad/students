#include<stdio.h>
main()
{
	int a=8;
	a=a&a-1;
	if(a==0)
		printf("yes");
	else
		printf("no");
}

