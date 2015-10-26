#include <stdio.h>
void showbits(int num);
int main()
{
	int a=42, b=0;
	printf("Before swap even and odd\n");
	showbits(a);
	b = swapeo(a);
	printf("After swap even and odd\n");
	showbits(b);
	return 0;
}

int swapeo(int num)
{
	unsigned int even_bits = 0XAAAAAAAA;
	unsigned int odd_bits = 0X55555555;
	even_bits &= num;
	odd_bits &=num;
	return (even_bits>>1 | odd_bits<<1);
}
