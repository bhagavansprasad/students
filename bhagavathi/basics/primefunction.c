#include<stdio.h>
int prime(int a);
main()
{
	int n=19,c=0;
	c=prime(n);
	if(c==1)
	{
		printf("this is not a prime number:%d\n",n);
	}
	else
	{
		printf("this is a prime number:%d\n",n);
	}
}
int prime(int a)
{
	int i,f=0;
	for(i=2;i<=a-1;i++)
	{
		if(a%i==0)
		{
			f=1;
			break;
		}
	}	
	return f;
}
