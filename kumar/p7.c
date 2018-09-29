#include<stdio.h>
int main()
{
	int i=1,n=5,j=1,k=1,l=1;
	for(i=1;i<=n;i++)
	{
		printf("%d",i);
	}
	printf("\n");
	for(l=1;l<=n-2;l++)
	{
	for(j=1;j<=n;j++)
	{
	if(j ==2 || j ==3 || j ==4)
	printf(" ");
	else
	printf("%d",j);
	}
	printf("\n");
	}
	for(k=1;k<=n;k++)
	{
		printf("%d",k);
	}
}


