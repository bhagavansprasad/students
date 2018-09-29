#include<stdio.h>
int factorial=1;
main()
{
	int i,n=5,s=0;
	for(i=1;i<=n;i++)
	{
		s=s+get_factorial(i+1)/get_factorial(i);
		printf("%d\n",s);
	}
}
int get_factorial(int n)
{
	int j,fact=1;
	for(j=1;j<=n;j++)
	{
		fact=fact*j;
	}
	return fact;
}

