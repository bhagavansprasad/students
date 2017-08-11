#include<stdio.h>

int main()
{
	int a=6 , b = 3 , t;

	t = mul(a, b);

	printf("%d\n",t);
}

int mul(int m, int n)
{
	if( n == 0)
		return 1;

	else if(n==1)
		return m;

	return(m + mul(m, n - 1));
}
