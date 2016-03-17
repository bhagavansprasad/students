#include<stdio.h>
int n=2,t=0;
main()
{
	int s=0,count=5,a=0;
	while(t<count)
	{
		a=is_prime(n);
		s=s+a;
		n++;
	}
	printf("sum %d", s);
}
int is_prime(n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		{
			break;
		}
	}
	if(n==i)
	{
		t++;
		printf("%d\n",n);
		return n;
	}
	else
		return 0;
}
