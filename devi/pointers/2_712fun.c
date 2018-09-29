#include <stdio.h>
void fun1((int*) (*fptr)(int,float))
{
	int *p;
	int x = 10;
	float y = 20.90;
	p = fptr(x,y);
	printf(" the addr is %u\n", p);
}
