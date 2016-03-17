#include<stdio.h>
main()
{
	int i,sum=0,n=5,a, b, c;
	for(i=1; i <= n; i++)
	{
		a = factorial (i+1);
		b = factorial (i);
		c = a/b;
		//printf("%d\n",c);
		sum = sum + c;
		printf("%d\n", sum);
	}
}
int factorial (int x)
{
int fact=1,i;
	for(i=1; i<=x; i++)
	{
		fact = fact * i;
	}
		//printf("%d\n--------", fact);
	return fact;
}

