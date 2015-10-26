#include <stdio.h>
int main()
{
	int *p = NULL;
	p++;
	p = 0x2000;
	printf("%p %d\n", p,*p);
	return 0;
}
