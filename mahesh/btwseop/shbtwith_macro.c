#include<stdio.h>
#define _BV(x) (1<<x)
void showbits(unsigned char n);

main()
{
	unsigned char a=85;
	printf("binary  ");

		showbits(a);
		printf("\n");
}
void showbits(unsigned char n)
{
unsigned char mask,k; 
char i;
	for(i=7;i>=0;i--)
	{
		mask=_BV(i);
		k=n&mask;
		k==0?printf("0"):printf("1");
	}
}
