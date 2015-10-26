#include <stdio.h>
main()
{
	int num=68,i,mask;
	displaybits(num);
	for(i=0;i<=31;i++)
	{
		mask=1<<i;
		if((num&mask)!=0)
		break;
	}
	for(i=i+1;i<=31;i++)
	{
		mask=1<<i;
		num=num^mask;
	}
	displaybits(num);
}
void displaybits(int num)
{
	int i;
	for(i=32;i>0;i--)
	{
		putchar(num&(1<<i)?'1':'0');
		if(i%8==0)
		putchar(' ');
	}
	printf("\n");
}
