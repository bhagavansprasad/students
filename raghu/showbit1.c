#include <stdio.h>
main()
{
	show_bit(10);
}

int show_bit(int n)
{
	int i,mask;
	for(i=32;i>=0;i--)
	{
		mask = n & 1<<i;
		((mask == 0)?printf("0"):printf("1"));
	}
	printf("\n");
}
