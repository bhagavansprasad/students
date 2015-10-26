#include <stdio.h>
//static int i=10;
//char j='i';
//extern float k=30.05;//shows warning
int main()
{
	extern int i;
	extern char j;
	extern float k;
	printf("%d %c %f", i, j, k);
	return 0;
}

// o/p: 10 i 30.499999
