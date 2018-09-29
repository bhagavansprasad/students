#include <stdio.h>

main()
{
	int i = 10, result, n = 5;

	while(n > 0)
	{
		n = n >> i;
		result = 1 & n;
		printf("%d", result);
		i++;
	}   
}
