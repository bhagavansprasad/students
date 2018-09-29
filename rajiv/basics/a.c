#include <stdio.h>
main()
{
	int a=426,b,c,d;
	c=a%10;
	a=a/10;
	b=a%10;
	a=a/10;
	d=a+b+c;
	printf("%d\n",d);
}
