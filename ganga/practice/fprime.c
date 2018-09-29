#include "stdio.h"
int n = 11;

int main()
{
	int retval = fprime(n);

	if(retval == 1)
	{
		printf("not prime\n");
	}
	
	else
	{
		printf("prime number\n");
	}
}

int fprime(int n)
{
	int i;

	for(i = 2; i < n; i++)
	{
		if(n % i == 0)
			break;
	}

	if(i == n)
		
		return 0;
	else
		
		return 1;
}



/*
#include <stdio.h>
void prime(int);
main()
{
	prime(2);
	prime(20);
	prime(71);
	prime(13);
	prime(12);
}
void prime(int n)
{
	int i=1,c=0;
	while(i<=n)
	{
		if(n%i==0)
		{
			c++;
		}
		i++;
	}
	if(c==2)
	{
		printf("prime\n");
	}
	else
		printf("not a prime\n");
}*/
