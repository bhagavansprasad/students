#include <stdio.h>

main()
{
	int x = 8, y = 2, i = 0 , j = 0;
	while(x > 0)
	{
		x = 1 << i;
		i++;
	}
	printf("%d\n", i);
	
	while(y > 0)	
	{
		y = 1 << j;
		j++;
	}
	printf("%d\n", y);

	if( i > j)
		printf("x is greater than y");

	else
		printf("x is less than y");
}
