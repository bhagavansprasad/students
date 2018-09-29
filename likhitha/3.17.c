#include <stdio.h>
int main()
{
	char ch=65;
	int n=5,i,j,k;
	for(i=1 ; i<=n ; i=i+2)
	{
		for(k=1;k<=((n-i)/2);k++)
		{
			printf(" ");
		}
		for(j=1 ; j<=i ; j++)
		{
			printf("%c",ch);
			ch=ch+1;
		}
		ch=65;
		printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		for(k=1;k<=i;k++)
		{
			printf(" ");
		}
		for(j=(n-i);j>i;j--)
		{
			printf("%c",ch);
			ch=ch+1;
		}
		ch=65;
		printf("\n");
	}
}

