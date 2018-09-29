#include <stdio.h>
int main()
{
	extern int i=10;//trying to inintiallize extern var locally :error will occur
	extern int j;
	i=10;
	extern int k;
	int k = 10;
	printf("%d %d %d", i, j, k);
	return 0;
}
