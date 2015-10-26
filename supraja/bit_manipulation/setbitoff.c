#include <stdio.h>
int set_bit_value(int n, int pos)
{
 return	n = 1<< pos ^ n;
}

int main()
{
	unsigned int a=0xff;
	unsigned int b=8;
	showbits(a);
	a=set_bit_value(a, b);
	showbits(a);
}

