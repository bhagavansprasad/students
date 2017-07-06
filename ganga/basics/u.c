#include <stdio.h>

main()
{
	unsigned int x = -1;
	int y = ~0;
	
	if(x == y)
		printf("x and y values are same\n");
	else
		printf("x and y values are not same\n");
}
