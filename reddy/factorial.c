#include <stdio.h>
int main()

{
	int n = 5;
	int f = n;
	int i;

	for ( i = 1; i < n; i++)
	{
		f = f * i;
	}

	printf ("%d\n", f);
}

