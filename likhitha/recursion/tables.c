#include<stdio.h>

int main()
{
	int a=6 , b = 1 , t;
	for(b=1 ; b<=10 ; b++)
	{
		t = tables(a, b);

		printf("%d * %d = %d\n", a, b, t);
	}
}

int tables(int m, int n)
{
	if( n == 0)
		return 1;

	else if(n==1)
		return m;

	return(m + tables(m, n - 1));
}
