#include <stdio.h>
main()
{
	unsigned int a=10;
	unsigned int c;
	c=~a;
	printf("%d\n",c);
	show_bits(c);
	printf("\n");
}
int show_bits(int n)
{
	int i;
	for(i=7;i>=0;i--)
	{
		printf("%d\t",(n>>i)&1);
	}
}
