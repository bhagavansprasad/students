#include <stdio.h>
int main()
{
	unsigned int x=4;
	if(!(x & (x-1)) && x)
		printf("power of 2\n");
	else
		printf("not power of 2\n");
}
