#include<stdio.h>
int main()
{
	int i,j,k,l,n=5;
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=i;j++)
			printf("%d\n",j);
		for(l=1;l<=2*(n-i)-1;l++)
			printf(" ");
		for(k=i;k>0;k--)
			printf("%d",k);
	}
	for(i=1;i<=n;i++)
	{
		printf("%d",i);
		for(j=n-1;j>0;j--)
		{
			printf("%d\t",j);
		}
		printf("\n");
	}
}
