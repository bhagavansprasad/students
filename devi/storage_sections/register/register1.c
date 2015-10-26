#include <stdio.h>
int main()
{
	register int a = 10;
	int *p;
	p=&a;//addr of reg var 'A' REQUESTED:Error
	printf("%u", p);
}
