#include<stdio.h>
main()
{
	int i,t,n=5,sum=0;
	for(i=1;i<=n;i++)
	{
		t=get_fact(i);
		sum=sum+t;
	}
	printf("%d",sum);
}
int get_fact(int x)
{
	int j,f=1;
	for(j=x;j>0;j--)
	{
		f=f*j;
	}
	return(f);
}
