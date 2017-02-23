#include<stdio.h>
main()
{
	int n=1,k=10,i;
	for(i=1;i<=k;i++)
	{
		n=n%2;
		if(n==0)
		{
			printf("this is not prime number=%d\n",n);
		}
		else
		{
			printf("this is prime number=%d\n",n);
		}
		n=++i;
	}
}
