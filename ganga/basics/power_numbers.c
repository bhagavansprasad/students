#include <stdio.h>

main()
{
	int i, n = 5, a = n;
	printf("%d  ", n);
	for(i = 1; i < 10; i++)
	{
		n = n * a ;
		printf("%d  ", n);
	}
	printf("\n");
}

