#include<stdio.h>
void showbits(unsigned char m);

main()
{
	unsigned char n =0xD1,a,mask;
	int pos=4;
	mask=(1<<pos);
	showbits(n);
	printf("\n");
	showbits(mask);
	printf("\n");
	a=n&mask;
	a==0?printf("O\n"):printf("1\n");
}
void showbits(unsigned char m)
{ 
		int i;
		unsigned char a;
	for (i=7;i>=0;i--)
	{
		a=m&(1<<i);
		a==0?printf("0"):printf("1");
	}
}
