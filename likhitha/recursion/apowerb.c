#include<stdio.h>

int main()
{
	int a=6 , b = 3 , t;

	t = power(a, b);

	printf("%d\n",t);
}

int power(int m, int n)
{
	if( n == 0)
		return 1;

	else if(n==1)
		return m;

	return(m * power(m, n - 1));
}
