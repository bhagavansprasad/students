#include <stdio.h>
#include <stdlib.h>
#define MAXROW 3
#define MAXCOL 4
main()
{
	int *p,i,j;
	p = (int*)malloc(MAXROW*MAXCOL*sizeof(int));
	for(i=0;i<MAXROW;i++)
	{
		for(j=0;j<MAXCOL;j++)
		{
			p[i*MAXCOL+j] = i;
			printf("\nval-->%d\t addr-->%u",p[i*MAXCOL+j],&(p[i*MAXCOL+j]));
		}
	}
}
