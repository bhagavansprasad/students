#include"stdio.h"
  int main()
{
	int i,j,k,n=5;
	for(i=1;i<=n-1;i++)
	{
		for(k=1;k<=n-i;k++)
		{
			printf(" ");
		}
		for(j=1;j<=n-i;j--)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
