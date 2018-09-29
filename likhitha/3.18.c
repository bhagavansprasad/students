#include <stdio.h>
int main()
{
	char ch=65;
	int n=3,i,j;
	for(i=3 ; i>=1 ; i--)
	{
		for(ch=65,j=1;j<=n;j++,ch++)
		{
			if(j<=i)
			{
				printf("%c",ch);

			}
			else
			{
				printf(" ");
			}
		}

		for(ch=66,j=(n-1);j>=1;j--,ch--)
		{
			if(j<=i)
			{	
				printf("%c",ch);
				
			}
			else
			{
				printf(" ");
			}
		}
		
		printf("\n");
	}
	
	for(i=(n-1);i<=n;i++)
	{
		for(ch=65,j=1;j<=n;j++,ch++)
		{
			if(j<=i)
			{
				printf("%c",ch);
				
			}
			else
				printf(" ");
		}
		
		for(ch=66,j=(n-1);j>=1;j--,ch--)
		{
			if(j<=i)
			{
				printf("%c",ch);
				
			}
			else
				printf(" ");
		}
		
		printf("\n");
	}
}

