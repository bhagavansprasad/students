#include "stdio.h"

main()
{
	int a = 0,n= 0, i = 0,j = 0,k = 0,l = 0,m = 0;
	for(n = 0;n <= 3;n++)
	{
		for(i = 2-n;i >=0;i--)
		{
			printf(" ");
		}	
		for(k = 0;k <= n;k++)
		{
			printf(" ");
			printf("#");
		}
		printf("\n");
	}
	for(j = 0;j <= 4;j++)
	{
		printf("#");
		printf(" ");
	}
	printf("\n");
	for(l = 3;l >= 0;l--)
	{
		for(a = l;a <= 3;a++)
		{
			printf(" ");
		}
		for(m = l;m >= 0;m--)
		{
			printf("#");
			printf(" ");
		}
		printf("\n");
	}
}
