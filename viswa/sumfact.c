#include<stdio.h>
main()
{
	int a=0,b=1,c,d=1,n=5,i;
	for(i=1;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
		d=d+b;
	}
	printf("%d",d);
}
