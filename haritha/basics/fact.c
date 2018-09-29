#include<stdio.h>
int fact=1;
main()
{
	int n=10,t,i;
	for(i=1;i<=n;i++)
	{
		t=get_fact_value(i);
		printf("%d\n",t);
	}
}
int get_fact_value(i)
{
	int j;
	for(j=1;j<=1;j++)
	{
		fact=fact*i;
	}
	return fact;
}
