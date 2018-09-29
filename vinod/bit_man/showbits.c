#include <stdio.h>

void showbits(int num)
{
	unsigned int mask =1, k;
	int i = 0;
		
	for(i=(sizeof(num)*8-1) ; i>=0 ;i--)
	{
		k = num & (mask << i);
		k == 0 ? printf("0") : printf("1");
	}
	printf("\n");
}
