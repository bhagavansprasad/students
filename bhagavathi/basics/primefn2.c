#include<stdio.h>
int prime(int a);
main()
{
	int n=7,c=0;
	c=prime(n);
	if(n==c)
	{
		printf("this is a prime number%d\n",n);
	}
	else
	{
		printf("this is not a prime number%d\n",n);
	}
}
int prime(int a)
{
	int i;
	for(i=2;i<=a-1;i++)
	{
		if(a%i==0)
		{
			break;
		}
		return i;
	}
}

