#include<stdio.h>
int main()
{
	unsigned int a=55;
	showbits(a);
	a=toggle_bit_by_pos(a);
	showbits(a);
}

int toggle_bit_by_pos(int n)
{
		return n=((n&(0x000f))<<4|(n&(0x00f0))>>4|(n&(0x0f00))<<4|(n&(0xf000))>>4);
		printf("\n");
}
