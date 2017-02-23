#include<stdio.h>
int prime(int);
main()
{
	int c,i=10,k,n;
	for(k=1;k<=n;k++)
	{
		c=prime(i);
	}
}
int prime(int a)
{
	int f=1,n=10,i;
	for(i=1;i<=a;i++)
	{
		if(a%i==0)
		{
			f=0;
			break;
		}
	}
	if(f==1)
	{
		printf("prime numbers%d\n",i);
	}

}
