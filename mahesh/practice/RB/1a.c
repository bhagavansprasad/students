#include <stdio.h>
struct xx
{
	int x=0;
}val;
void main(void)
{
	val.x=3;
	printf("%d\n",val.x);
}
