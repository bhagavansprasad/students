#include<stdio.h>
main()
{
	int i=0,n=10,t=0,x=0,sum=0;
	for(i=1;i<=n;i++)
	{
		t=fact(i);
		printf("%d\n",t);
		sum=sum+t;
	}
	printf("%d\n",sum);
}
int fact(int n)
{
	int i=0,f=1;
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
	return f;
	}
