#include<stdio.h>
main()
{
	int n=5,sum=0,t,i;
	for(i=1;i<=n;i++)
	{
		t=fact_series_sum(i);
		sum=sum+t;
	}
	printf("%d",sum);
}
int fact_series_sum(int x)
{
	int f=1,j;
	for(j=1;j<=x;j++)
	{
		f*=j;
	}
	return(f);
}
