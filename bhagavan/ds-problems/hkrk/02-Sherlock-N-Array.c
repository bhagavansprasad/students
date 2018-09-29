#include "stdio.h"

char* solve(int a_size, int* a)
{
	char *py = "YES";
	char *pn = "NO";
	int i = 0, ls = 0, rs = 0, sum = 0, me = 0;

	for (i = 0; i < a_size; i++)
	{
		sum = sum + a[i];
	}

	for (i = 0; i < a_size; i++)
	{
		me = a[i];
		ls = ls + (i == 0 ? 0 : a[i-1]);
		rs = sum - (me + ls);
		printf ("%d %d %d %d\n", sum, ls, me, rs);
		if (ls == rs)
			return py;
	}

	return pn;
}

int main() 
{
	//int a[] = {1, 5, 3, 4, 2};
	int a[] = {1, 2, 3, 3};

	int a_size = sizeof(a)/sizeof(int);

	char *result = solve(a_size, a);

	printf ("result :%s\n", result);
}
