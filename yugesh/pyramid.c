#include <stdio.h>
main()
{
	int i,j,n=5;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n-i; j++)
			printf(" ");
		for(j=1; j<=2*i-1; j++)
			printf("1");
		printf("\n");
	}
	n--;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=i; j++)
			printf(" ");
		for(j=1; j<=2*(n-i)+1; j++)
			printf("1");
		printf("\n");
	}
}
