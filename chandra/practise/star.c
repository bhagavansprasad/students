#include<stdio.h>
main()
{
	int i, j;
	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < 7; j++)
		{
			if(i == 0 ||i == 6 || j == 0 || j == 6)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

