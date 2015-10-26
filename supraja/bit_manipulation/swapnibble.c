#include<stdio.h>
int main()
{
	int a=10;
	showbits(a);
	a=swap_nibble(a);
	showbits(a);
}

int swap_nibble(int n)
{
	return	n=((n&(0x0f))<<4|(n&(0xf0))>>4);
	}
