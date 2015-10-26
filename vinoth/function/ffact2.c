#include<stdio.h>
main()
{
	int n=5, sum=0, a, b, c, x, y, i;	
	for(i=0; i<=;; i++)
	{
		a = factorial (x+1);
		b = factorial (y+1);
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

