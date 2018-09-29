#include<stdio.h>
int main()
{
	unsigned int a = 10;

	showbits(a);

	a = set_alternatebit_on(a);

	showbits(a);
}

int set_alternatebit_on(unsigned int n)
{
	//n = n >> 32;

	n = 0x55555555;

	return n;
}
