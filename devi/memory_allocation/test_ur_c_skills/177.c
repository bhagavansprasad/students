#include <stdio.h>
#include <stdlib.h>
#define MAXROW 3
#define MAXCOL 4
main()
{
	int **p,i,j;

	p = (int **)malloc(MAXROW*sizeof(int*));
	p[0] = (int *)malloc(MAXROW*MAXCOL*sizeof(int*));
	for(i=0;i<MAXROW;i++)
	{
		p[i] = p[0]+i*MAXCOL;
	}

	for(i=0;i<MAXROW;i++)
	{
		for(j=0;j<MAXCOL;j++)
		{
			p[i][j]=i;
			printf("val-->%d\taddr-->%u\n",p[i][j],&p[i][j]);
		}
		printf("\n");
	}
}
