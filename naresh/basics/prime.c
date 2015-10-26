#include<stdio.h>
main()
{
	int x=7,i=0,t=0;
	t=is_prime(x);
	if(t==0)
	printf("prime\n");
	else
	printf("not prime\n");
	}
	int is_prime(int n)
	{
	int i=0;
	for(i=2;i<=n-1;i++)
	{
		if(n%i==0)
		return 1;
		}
		return 0;
	}


