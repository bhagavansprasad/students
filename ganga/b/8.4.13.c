#include<stdio.h>
main()
{
	int a=9,b=1,c=0;
	a=~a;
	b=~b;
	c=a&b;
	c=~c;
	printf("%d",c);
}

