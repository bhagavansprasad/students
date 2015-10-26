#include<stdio.h>
main()
{
	int i=0,t=0,sum=0,n=10;
	for(i=2;i<=10;i++)
	{
		sum=sum+(fact(i)/fact(i-1));
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
