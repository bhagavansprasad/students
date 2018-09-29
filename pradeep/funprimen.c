#include <stdio.h>
int main()
{
	int i,t,c=0,n=7;
	for(i=2;c<n;i++)
	{
		t=is_prime(i);
		if(t==1)
		{
			printf("%d",i);
			c=c+1;
		}
	}
}
int is_prime(int num)
{
	int i,t=0;
	for(i=2;i<=num-1;i++)
	{
		t=num%i;
		if(t==0)
		{
			return 0;
		}
	}
	if(t!=0)
	{
		return 1;
	}
}
