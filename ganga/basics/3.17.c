#include<stdio.h>

void main()
{
	int i,j,k;
	for(i=0;i<=2;i++)
	{
		for(j=i;j<3;j++)
		{
			printf(" ");
		}
		for(k=65;k<=65+(i*2);k++)
		{
			printf("%c",k);
		}
		printf("\n");
	}
	
	for(i=1;i>=0;i--)
	{
		for(j=3;j>i;j--)
		{
			printf(" ");
		}
		for(k=65;k<=65+(i*2);k++)
		{
			printf("%c",k);
		}
		printf("\n");
	}
}
