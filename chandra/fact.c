#include<stdio.h>
main()
{
	int i,fact=1;
	for(i=5;i>=1;i--)
	{
		fact=fact*i;
	}
	printf("%d",fact);
}
