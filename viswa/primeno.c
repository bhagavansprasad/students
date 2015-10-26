#include<stdio.h>
main()
{
	int n=5,t;
	if((t=is_prime(n))==0)
	{
		printf("not a prime no.");
	}
	else
	{
		printf("it is a prime no.");
	}
}
int is_prime(int x)
{
	int i;
	for(i=2;i<(x-1);i++)
	{
		if(x%i==0)
		{
			return(0);
		}
	}
	if(i>=x)
	{
		return(1);
	}
}
