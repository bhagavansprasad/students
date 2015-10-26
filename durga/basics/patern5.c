#include<stdio.h>

main()
{
	int i, j, k, n = 6;

	for (k = 1; k <= 5; k++)
	{
		for(i = 1; i <= (n-k); i++)
			printf("%d",i);

		if (i == 6)
			i=i-1;

/*
#if 0
		if (k == (2,4))
			printf(" ");
		else if (k >= 3)
//			for (j = 1; j <= k; i++)
//				printf(" ");
#endif
*/

		if(k == 5)
			printf("  ");

		for(j = i-1; j > 0; j--)
			printf("%d",j);

		printf("\n");
	}
}

