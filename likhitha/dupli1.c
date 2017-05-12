#include <stdio.h>
int main()
{
	char ch=65;
	int n=3,i,j;
	for(i=3 ; i>=1 ; i--)
	{
		for(j=1 ; j<=n ; j++)
		{
	if(j<=i)
	printf("%c",ch);
	ch=ch+1;
	else
	printf(" ");
		}

		ch=ch-1;
		for(j=(n-1); j>=1 ;j--)
		{
			if(j<=i)
			printf("%c",ch-1);
		else
		printf(" ");
	     }
	ch=65;
	printf("\n");
}
}
