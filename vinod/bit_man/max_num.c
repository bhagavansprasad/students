#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 20, b = 54;
	int i = 0;
	unsigned int mask = 1;

	for(i=sizeof(a)*8 - 1 ; i>=0 ; i--)
	{
		mask = 1;
		mask <<= i;
		if((a & mask) != (b & mask))
		{
			if((a & mask) != 0)
			{	
				printf("%d is greater than %d(a>b)\n", a, b);
				exit(0);
			}
			else
			{
				printf("%d is greater than %d(b>a)\n", b, a);
				exit(0);
			}
		}
	}
	printf("%d and %d are same(a=b)\n", a, b);
	return 0;
}

