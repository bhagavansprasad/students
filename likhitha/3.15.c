#include <stdio.h>
int main()
{
	int n=5,i,j;
	for(i=5 ; i>=1 ; i--)
	{
		for(j=1 ; j<=n ; j++)
		{
			if(j<=i)
				printf("%d",j);
			else
				printf(" ");
		}
		for(j=(n-1) ; j>=1 ; j--)
		{
			if(j<=i)
				printf("%d",j);
			else
				printf(" ");
		}
	printf("\n");
	}
}

