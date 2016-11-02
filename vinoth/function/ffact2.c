#include<stdio.h>
main()
{
	int n=5, sum=0, a, b, c, x=0, y=0, i;	
	for(i=1; i<=n; i++)
	{
		a = factorial (i+1);
		b = factorial (i);
		c = a/b;
		//printf("%d\n",c);
		sum = sum + c;
		printf("%d\n",sum);
	}
}
int factorial (int p)
{
	int i=1, fact=1;
	for(i=1; i<=p; i++)
	{
		fact = fact * i;
		//printf("%d\n",fact);
	}
	return fact;
}

