#include <stdio.h>
#include <stdlib.h>
#define MAXROW 3
#define MAXCOL 4
main()
{
	int **p,i,j;
	p = (int**)malloc(MAXROW*sizeof(int));
	for(i=0;i<MAXROW;i++)
		p[i] = (int*)malloc(MAXCOL*sizeof(int));
	for(i=0;i<MAXROW;i++)
	{
		for(j=0;j<MAXCOL;j++)
		{
			p[i][j] = i;
			printf("\nval-->%d\t addr-->%u",p[i][j],&p[i][j]);
		}
	}
}
