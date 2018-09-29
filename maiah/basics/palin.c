#include<stdio.h>
main()
{
	int a=626,c=0;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	c=(c*10)+(a%10);
	a=a/10;
	printf("%d",c);
}
