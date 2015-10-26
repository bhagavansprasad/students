#include <stdio.h>
int main()
{
	int a = 0;
	int b = 1;
	int n = 15;
	int i;

	printf (" %d %d " , a , b );

	for ( i = 1; i <= n; i +=2)
	{
		a = a + b;
		b = a + b;
		printf (" %d %d " , a , b );

	}
	printf ("\n");

}
