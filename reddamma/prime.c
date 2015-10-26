#include<stdio.h>
main()
{
	int n=5,i,t;
	for(i=2;i<=n;i++)
	{
		t=is_prime(i);


		printf("%d",t);
	}
}
int is_prime(int n)
{
	int j;
	for(j=2;j<n-1;j++)
	{
		if(n%j==0)
		break;
	}
	if(n==j)
		return n;
}
