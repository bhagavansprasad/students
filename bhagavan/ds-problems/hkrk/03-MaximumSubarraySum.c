#include "stdio.h"

long int maximumSum(int a_size, long int* a, long int m) 
{
	int sum = 0;
	int i = 0, j = 0, mod = 0, big = 0;

	for (i = 0; i < a_size; i++)
	{
		sum = 0;
		for (j = 0; j < i && j+i <= a_size; j++)
		{
			sum = sum + a[j];
		}

		mod = sum % m;
		if (mod > big)
			big = mod;
	}

	return big;
}

int main() 
{
	long int a[] = {3, 3, 9, 9, 5};
	long int m = 7;
	int a_size = sizeof(a)/sizeof(int);
	long int result = maximumSum(a_size, a, m);

	printf ("result :%ld\n", result);
}
