#include<stdio.h>
main()
{
	int a=11,i;
	for(i=0;a;i++)
		a=a&a-1;
	if(i%2==1)	
		printf("1");
	else
		printf("0");
}


