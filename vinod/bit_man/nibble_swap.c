#include <stdio.h>
void showbits(int num);

int main()
{
	unsigned char a=0XD8;
	printf("Before nibble swap\n");
	showbits(a);
	a = (a<<4) | (a>>4);
	printf("After nibble swap\n");
	showbits(a);
	return 0;
}
