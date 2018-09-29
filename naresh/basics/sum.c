#include<stdio.h>
main()
{
	int x=10,i=0,n,t=0,sum=0;
	for(i=1;i<=n;i++)
	{
		t=is_prime(x);
		if(t==0)
			sum=sum+t;
	}
	printf("%d",sum);
}
int is_prime(int n)
{
	int i=0;
	for(i=2;i<n-1;i++)
	{
		if(n/i==0)
			return 1;
	}
	return 0;
}

