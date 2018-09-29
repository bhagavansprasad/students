#include<stdio.h>
main()
{
	int i,n=5,a=0,b=1,c,d=0;
	for(i=0;i<=n;i++)
	{
		d=d+a+b;
		c=a+b;
		a=b;
		b=c;
	}
	printf("%d",d);
}
