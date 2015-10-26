#include <stdio.h>
void showbits(int num);
int main()
{
	unsigned char a=0X5;
	printf("Before nibble reverse\n");
	showbits(a);
	a = (a>>3 | a<<3) | ((a>>2)<<3)>>2 | ((a>>1)<<3)>>1 ;
	printf("After nibble reverse\n");
	showbits(a);
	return 0;
}
