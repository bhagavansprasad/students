#include<stdio.h>
void showbits(unsigned char );
main()
{
	unsigned char n=0x6D,a,bb,b,cc,c,o;
	showbits(n);
	printf("\n");
	a=n&0xF0;
	showbits(a);
	printf("\n");

	bb=n<<6;
		showbits(bb);
	printf("\n");

	b=bb>>4;
		showbits(b);
	printf("\n");

	cc=n<<4;
		showbits(cc);
	printf("\n");

	c=cc>>6;
		showbits(c);
	printf("\n");

	o=a|b|c;
	printf("%X\n",o);
		showbits(o);
	printf("\n");

}
void showbits(unsigned char m)
{
	int i;
	unsigned char j,mask;
	for(i=7;i>=0;i--)
	{
		mask=(1<<i);
		j=m&mask;
		j==0?printf("0"):printf("1");
	}
}
