#include<stdio.h>
main()
{
	int a=143,c1=0,c2=0;
	c1=(c1*10)+(a%10);
	a=a/10;
	c2=(c2*10)+(a%10);
	a=a/10;
	printf("%d%d%d\n",c1,c2,a);
}
