#include <stdio.h>
int main()
{
	int n=5,i,j ,k ;
	for(i=1 ; i<=n ; i++)
	{
		for(k=n-i ; k>=1 ;k--)
		{
			printf(" ");
		}
		for(j=1 ; j<=i ; j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
