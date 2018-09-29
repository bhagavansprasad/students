#include <stdio.h>
void displaybits(int x);
main()
{
	int x=20;
	displaybits(x);
	return 0;
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
