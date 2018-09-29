#include <stdio.h>
void displaybits(int x);
unsigned int reverse(unsigned int num);
int main(void)
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
	int i,mask;
	for(i=31;i>=0;i--)
	{
		mask=1<<i;
		putchar((x&mask)?'1':'0');
		if(i%8==0)
		putchar(' ');
	}
	printf("\n");
}
