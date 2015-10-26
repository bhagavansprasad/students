#include <stdio.h>
int factorialfunction(int );
main()
{
	int n=5,a,fact,i ;
	a=factorialfunction(5);
	printf("%d",a);
}
int factorialfunction(int n)
{
	int fact=1,i;
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
	}
	printf("%d\n",fact);
	return fact;
}

