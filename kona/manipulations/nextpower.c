#include <stdio.h>
unsigned nextpower(unsigned int n);
void displaybits(int x);
main()
{
	unsigned int n=100;
	displaybits(n);
	displaybits(nextpower(n));
	printf("value is %d\n",nextpower(n));
}
unsigned nextpower(unsigned int n)
{
	int i;
	if(n&&!(n&(n-1)))
	return n;
	i=-1;
	while(n!=0)
	{
		n>>=1;
		i++;
	}
	return 1<<(i+1);
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
