#include <stdio.h>
//	register int b;
//	register int a;
int main()
{
	register int b;
	register int a;
	printf("%d %d", &a, &b);// Error: addr of reg var 'a' / 'b' requested
	return 0;
}
