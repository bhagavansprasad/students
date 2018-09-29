#include<stdio.h>
main()
{
	int n=5,i,t;
	for(i=1;i<=n;i++)
	{
		t=get_factorial(i);
			printf("%d",t);
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
