#include<stdio.h>
main()
{
	int a=0,b=1,i,n=5,c=0;
	for(i=0;i<n;i++)
	{
		c=a+b;
		a=b;
		b=c;
		printf("%d\r\n",c);
	}
}
