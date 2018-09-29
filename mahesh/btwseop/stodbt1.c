#include<stdio.h>
void showbits(unsigned char n);

main()
{
	unsigned char a=225;
	char i=1;
	showbits(a);
	while(i<=7)
	{
		a|=1<<i;
		i=i+2;
	}	printf("\n after");
	
	showbits(a);
}
void showbits(unsigned char n)
{
unsigned char mask,k; 
char i;
	for(i=7;i>=0;i--)
	{
		mask=1<<i;
		k=n&mask;
		k==0?printf("0"):printf("1");
	}
}
