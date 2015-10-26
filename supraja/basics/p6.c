#include <stdio.h>
int main()
{
	int n=5,i,j,k=1;
	for( ; n>=1;n--,k++)
	{	
		for(i=1;i<=n;i++)
		{
			printf("%d",i);
		}
		for(j=k;j>1;j--)
		{	
			printf(" ");
		}
		for(j=k;j>1;j--)
		{
			printf(" ");
		}
		for(i=n;i>=1;i--)
		{
			printf("%d",i);

		}
		printf("\n");
	}
}



