#include <stdio.h>

void main()
{
	int i, j;
	for(i = 0 ; i < 5 ; i++)
	{
		for(j = 0 ; j < i ; j++)
		{
			if(j % i  == 0)
				printf("%3d", j);

			else
				printf("%3d", j);
		}

		printf("\n");
	}
}
