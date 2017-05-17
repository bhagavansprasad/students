#include <stdio.h>
main()
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		printf("%d\n",i);
		for(j=1;j<=5;j++)
		{
			printf(" %d",j);
		}
		printf("\n");
	}
	printf("i:%d,j:%d\r\n",i,j);
}
