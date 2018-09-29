#include <stdio.h>
int main()
{
	int n=10 , i ,a,b , sum=0 ;
	for(i=1 ; i<=n ; i++)
	{
		b=factorial(i);
		a=factorial(i+1);
		sum=sum+(a/b);
	}
	printf("%d\n",sum);
}

int factorial (int n)
{
	int i,fact=1;
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
	}
	return fact;
}
