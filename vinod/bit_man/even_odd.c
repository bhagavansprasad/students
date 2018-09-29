#include <stdio.h>
int main()
{
	int n = 325;
	unsigned int mask =1, k;
	
	if(n & mask)
		printf("Given %d is odd\n", n);
	else
		printf("Given %d is even\n", n);
	return 0;
}
