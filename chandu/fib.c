#include<stdio.h>
main()
{
	int a=0,b=1,c=0,i=1,n=5;
	for(i=1;i<=n;i++)
	{
		printf("%d",c);
		c=a+b;
		a=b;
		b=c;
	}
}
