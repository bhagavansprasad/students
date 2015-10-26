#include<stdio.h>
#define _BV(x) (1<<x)
void showbits(unsigned char n);
void check(unsigned char m,unsigned char i);
main()
{
	unsigned char n=41,p1=3,p2=6,p3=7;
	printf("\n binary");

		showbits(n);
		printf("\n");
		check(n,p1);
			printf("\n");
			check(n,p2);
				printf("\n");
				check(n,p3);
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
void check(unsigned char m,unsigned char i)
{
	unsigned char k=m&(1<<i);
	k==0?printf("0"):printf("1");
}
