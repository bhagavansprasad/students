#include<stdio.h>
main()
{
	int n=5,t,i;
	for(i=1;i<=n;i++)
	{
		t=fact_series_values(i);
		printf(" %d ",t);
	}
}
int fact_series_values(int x)
{
	int f=1,j;
	for(j=1;j<=x;j++)
	{
		f*=j;
	}
	return(f);
}
