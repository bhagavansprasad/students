#include<stdio.h>
int prime(int a, int b);
main()
{	
    int n=5,m=25,b;
	int c=0;
	b = int prime(n,m);
	if(c==2)
	{
		printf("this a prime number=%d\n",b);
	}
	else
	{
		printf("this is not a prime number%d\n",b);
	}

}
int prime(int a, int b)
{
	int n,i,c;
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			c++;
		}
	}
}

