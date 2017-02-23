#include <stdio.h>  
main() 
{
	int n,m,i,c = 0;
	printf("Enter any number n:");
	scanf("%d", &n);
		for (i = 1; i <= n; i++) 
		{
			if (n % i == 0) 
			{
				c++;
			}
		}
		for(m=1;m<=n;m++)
		{

			if (c == 2) 
			{
				printf("n is a Prime number\n");
			}
			else
			{
				printf("n is not a Prime number\n");
			}
	}
}  
