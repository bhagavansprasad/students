#include<stdio.h>
main()
{
	int a=-1,b=1,c,n=10,i;
	for(i=0;i<=n;i++)
	{
		c=a+b;
		printf("fibbonacci series of given number=%d\n",c);
		a=b;
		b=c;
	}
}
