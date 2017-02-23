#include<stdio.h>
main()
{
	int a=12345,b1,b2,b3,b4,c;
	b1=a%10;
	a=a/10;
	b2=a%10;
	a=a/10;
	b3=a%10;
	a=a/10;
	b4=a%10;
	a=a/10;
	c=b1+b2+b3+b4+a;
	printf("sum of digits=%d\n",c);
}
