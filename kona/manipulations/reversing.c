#include <stdio.h>
#include <stdlib.h>
void displaybits(int x);
unsigned int reverse(unsigned int num);
main()
{
	 unsigned int x=234242156;
	displaybits(x);
	displaybits(reverse(x));
	return 0;
}
unsigned int reverse(unsigned int num)
{
	unsigned int i,rev=0;
	for(i=0;i<32;i++)
		if((num&(1<<i)))
		rev=rev|(1<<(31-i));
		return rev;
}
void displaybits(int x)
{
	int i;
	for(i=32;i>0;i--)
	{
		putchar(x&(1<<i)?'1':'0');
		if(i%8==0)
		putchar(' ');
	}
	printf("\n");
}
