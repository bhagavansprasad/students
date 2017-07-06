#include<stdio.h>
main()
{
	int a=11,b=14,c=0;
	a=~a;
	b=~b;
	c=a|b;
	c=~c;
	printf("%d",c);
}

