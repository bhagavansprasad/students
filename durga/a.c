#include<stdio.h>
main()
{
	int i,j;
	for(i = 1; i<=6; i++)
	{
		if( i == 1|| i == 6)
		{
			for( j = 1; j<=6; j++)
			{
				printf("*");
			}
		}
		else
		for( j = 1; j<=6; j++)
		{
			if( j == 1 || j == 6)
			{
				printf("*");
			}
			else 
				printf(" ");
		}
		printf("\n");
		//	printf("%d\n",i);
	}
}

