#include<stdio.h>
main()
{
	int x,i=0,y,sum=0,n=10;
	for(i=1;i<=n;i++)
	{
		sum=sum+(fact(x)/fact(y));
	}
	printf("%d\n",sum);
}
int fact(int n)
{
	int i=0,f=1;
	for(i=0;i<=n;i++)
	{
		f=f*i;
	}
	return 1;
}
