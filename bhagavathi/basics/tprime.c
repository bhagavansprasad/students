#include<stdio.h>
int prime (int);
main()
{
	int n=30,c,i=2,count=0;
	for(;i<=n;i++)
	{
		c=prime(i);
		if(c==0)
		{
			printf("%d\n",i);
			count++;
		}
	}
}
int prime(int a)
{
	int j,f=0;
	for(j=2;j<=a-1;j++)
	{
		if(a%j==0)
		{
			f=1;
		}
	}
	return f;
}
