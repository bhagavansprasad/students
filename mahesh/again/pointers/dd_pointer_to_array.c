#include <stdio.h>
#include <stdlib.h>
#define ROW 3
main()
{
	int (*p)[4];
	int i, j;
	p = (int (*)[4])malloc(ROW*4*sizeof(int));
	for(i=0;i < ROW;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("enter element:\n");
			scanf("%d\n",&p[i][j]);
		}
	}
	printf("elements are :\n");
	for(i=0;i < ROW;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%3d",p[i][j]);
			//scanf("%d\n"&p[i][j]);
		}
		printf("\n");
	}

}
