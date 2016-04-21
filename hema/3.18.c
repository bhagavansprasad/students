#include<stdio.h>
main()
{
	int i,j;
	for(i=67;i>=65;i--)
	{	
		for(j=65;j<=67;j++)
		{
			if(j<=i)
				printf("%c",j);
			else
				printf(" ");
		}
		for(j=66;j>65;j--)
		{
			if(j<=i)
				printf("%c",j);
			else
				printf(" ");
		}
		printf("%c",j);
		printf("\n");
	}
	for(j=67;j>=65;j--)
	{
		for(i=65;i<=66;i++)
		{
			if(i<=j)
				printf("%c",i);
			else
				printf(" ");
		}

		for(i=67;i>65;i--)
		{
			if(i<j)
				printf("%c",i);
			else
				printf(" ");
		}
			printf("%c",i);
			printf("\n");
	}
}

