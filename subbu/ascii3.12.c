#include<stdio.h>
main()
{
char i='A',n=5,j,k=65;
	for(i='A';i<('A'+n);i++)
	{
		for(j='A';j<=k;j++)
		{
			printf("%C",j);
		}
		k++;
		printf("\n");
	}
}
