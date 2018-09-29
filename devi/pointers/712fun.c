#include <stdio.h>
void fun2(int (*fptr)(int,int))
{
	int x = 10, y = 20,z;
	z=fptr(x,y);
	printf("z is %d\n", z);
}
