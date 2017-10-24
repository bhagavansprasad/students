#include "stdio.h"

main()
{
	int rem = 0, i, n = 131, a = n;

	for(i = 0; i < 3; i++)
	{
		rem = ((rem * 10) + (n % 10));
		n = n / 10;
	}
	printf("rem is %d\n", rem);

	if(rem == a)
		printf("is a pallindrome \n");
	else
		printf("is not a pallindrome \n");
}
