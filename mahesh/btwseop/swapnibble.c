#include<stdio.h>
void showbits(unsigned char m);

main()
{
	unsigned char n=0xD9,a,b,o;
	showbits(n);
	printf("\n");
	a=(n&0x0F)<<4;
	b=(n&0xF0)>>4;
	o=a|b;
	printf("%X\n",o);
		showbits(o);
	printf("\n");


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
