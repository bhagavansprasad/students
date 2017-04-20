#include <stdio.h>

void main()
{
	prime_bw_two_num(20, 30);
}

int prime_bw_two_num(int i, int j)
{
	int k, c = 0, sum = 0;

	for(i ; i <= j; i++)
	{
	c = 0;
		for(k = 1; k <= i; k++)
		{
			if(i % k == 0)
				c++;
		}

		if(c == 2)
		{
			printf("%d\t", i);

			sum = sum + i;
		}
	}	
	printf("sum :%d \n", sum);
}
