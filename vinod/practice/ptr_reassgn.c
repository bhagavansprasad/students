#include <stdio.h>
int main()
{
	int *p = (int *)0x0;
	*p = 0x4000;
	printf("%p %d\n", p, *p);
	//*(int *)0x2000 = 0x4000;
	return 0;
}
