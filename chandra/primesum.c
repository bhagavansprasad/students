#include<stdio.h>
main()
{
	int i,t,n=10,c=0,sum=0;
	for(i=1;c<n;i++)
	{
		t=get_prime(i);
		sum=sum+t;
		if(t!=0)
		{
			c++;
		}
	}
	printf("%d ",sum);
}
int get_prime(int x)
{
	int j;
	for(j=2;j<=(x-1);j++)
	{
		if(x%j==0)
		{
			return(0);
		}
	}
	if(j>=x)
	{
		return(x);
	}
}
