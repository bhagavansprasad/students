#include <stdio.h>
main()
{
	int i,j;
	for(i=0;i<=10;i++)
	{
		for(j=65;j<=(75-i);j++)
		{
			printf("%c ",j);
		}
		printf("\n");
	}
}
