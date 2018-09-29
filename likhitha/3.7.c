#include <stdio.h>
int main()
{
	int n=10 , i , t , count=1, sum=0 ;
	for(i=1 ; count<=n ; i++)
	{
		t=factorial(i);
		sum=sum+t;
		count++;
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
