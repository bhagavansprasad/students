#include<stdio.h>
main()
{
	int n=5,t,sum=0,i;
	for(i=1;i<=n;i++)
	{
		t=(f_series_sum_n(i+1)/f_series_sum_n(i));
		sum+=t;
	}
	printf("%d",sum);
}
int f_series_sum_n(int x)
{
	int j,f=1;
	for(j=1;j<=x;j++)
	{
		f*=j;
	}
	return(f);
}
