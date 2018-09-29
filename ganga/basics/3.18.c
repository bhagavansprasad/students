#include<stdio.h>
void main()
{
	int i,j,k;
	for(i=67;i<=65;i++)
	{
		for(j=65;j<=67;j++)
		{
			if(j<=i)
				printf("%c",j);
			else
				printf(" ");
		}
		for(j=66;j>=65;j--)
		{
			if(j<=i)
				printf("%c",j);
			else
				printf(" ");
		}
		printf("\n");
	}
	for(k=66;k<=67;k++)
	{
		for(i=65;i<=66;i++)
		{
			if(i<=k)
				printf("%c",i);
			else
				printf(" ");
		}
		for(i=67;i>=65;i--)
		{
			if(i<=k)
				printf("%c",i);
			else
				printf(" ");
		}
	}
	printf("\n");
}
