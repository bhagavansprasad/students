#include<stdio.h>
main()
{
	int i=0,count=0,n=25,t=0,s=0;
	for(i=1;count<=n;i++)
	{
		t=is_prime(i);
		if(t==0)
			printf("prime\n");
		count++;
		s=s+t;
	}
	printf("%d\n",count);
}
int is_prime(int n)
{
	int i=0;
	for(i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			return 0 ;
		}

	}
}
