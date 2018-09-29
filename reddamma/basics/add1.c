#include<stdio.h>
main()
{
	int a=426,c=0;
	c=c+a%10;
	a=a/10;
	c=c+a%10;
	a=a/10;
	c=c+a%10;
	a=a/10;
	printf("%d",c);
		printf("\n");
}

