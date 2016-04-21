#include<stdio.h>
main()
{
	int i, j, k = 0;
	int n = 3;
	int sp = 0;

	for(i = 1; i <= n; i++)
	{	
		for(j='A'; j <= ('A' + n)-i; j++)
				printf("%c", j);

		for(k = 1; k <= sp; k++)
		{
			printf(" ");
		}

		if (i == 1)
		{
			sp = sp + 1;
			j  = j - 2;
		}
		else
		{
			sp = sp + 2;
			j  = j - 1;
		}

		for(; j >= 'A'; j--)
			printf("%c", j);

		printf("\n");
	}

	sp =  sp - 4; 
	for(i = 1; i <= n-1; i++)
	{
		for(j='A'; j <= 'A' + i; j++)
				printf("%c", j);

		for(k = 1; k <= sp; k++)
		{
			printf(" ");
		}

		if (i == n-1)
		{
			sp = sp - 1;
			j  = j - 2;
		}
		else
		{
			sp = sp - 2;
			j  = j - 1;
		}

		for(; j >= 'A'; j--)
			printf("%c", j);

		printf("\n");
	}
}

