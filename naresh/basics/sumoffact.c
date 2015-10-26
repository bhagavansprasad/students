#include<stdio.h>
main()
{
	int n=23,i=0,t=0,sum=0;
	for(i=1;i<=n;i++)
	{
		t=is_prime(i);
		if(t==0)
			printf("%d\n",t);
		sum=sum+t;
	}
	printf("%d\n",sum);
}
int is_prime(int n)
{
	int i=0;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
			return 1;
	}
	return 0;
}

