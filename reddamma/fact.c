#include<stdio.h>
main()
{
	int a=10,t;
	t=get_factorial(a);
	printf("%d",t);
}
int get_factorial(int n)
{
	int i,fact=1;
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
	}
	return fact;
}
