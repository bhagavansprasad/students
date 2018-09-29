#include<stdio.h>
int main()
{
	int n=5,i,j ,k ;
	for(i=1 ; i<=n ; i++)
	{
		for(k=0 ; k<i-1 ;k++)
		{
			printf(" ");
		}
		for(j=1 ; j<=(n+1-i) ; j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
