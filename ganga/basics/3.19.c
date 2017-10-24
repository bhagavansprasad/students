#include<stdio.h>

int fact(int n)
{
	int i = 0, fact = 1;
	
	for(i = 1; i <= n; i++)
	{
		fact = fact * i;
	}
	return fact;
}

int main()
{
	int n = 6, i = 0, j = 0, a = 0, b = 0, c = 0;

	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ;j <= (n - i - 2) ; j++)
		{
			printf(" ");
		}

		for(j = 0; j <= i ; j++)
		{
			a = fact(i);
			b = fact(j);
			c = fact(i - j);
			printf(" %d",(a / (b * c)));
		}
		printf("\n");
	}
	return 0;
}
