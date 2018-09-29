#include<stdio.h>
main()
{
	int i,t,n=5;
	for(i=1;i<=n;i++)
	{
		t=get_fact(i);
		printf("%d",t);
	}
}
int get_fact(int x)
{
	int j,f=1;
	for(j=1;j<=x;j++)
	{
		f=f*j;
	}
	return(f);
}
