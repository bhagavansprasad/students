#include <stdio.h>
int main()
{
	int count_Setbits(int num);
	int n = 1;
	int count = 0;
	printf("The given no in binary form -> ");
	count = count_Setbits(n);
	printf("\nNumber of set bits -> %d\n", count);
	if( count > 1 )
		printf("Given no %d is not power of 2\n", n);
	else
		printf("Geven no %d is power of 2\n", n);
	return 0;
}

int count_Setbits(int num)
{
	unsigned int mask =1, k;
	int i = 0;
	int count = 0;
	
	for(i=(sizeof(num)*8-1) ; i>=0 ;i--)
	{
		k = num & (mask << i);
		if(k != 0)
			count++;
		k == 0 ? printf("0") : printf("1");
	}
	
	return count;
}
