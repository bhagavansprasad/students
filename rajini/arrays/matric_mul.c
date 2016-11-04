#include <stdio.h>
#define ROWS1 3
#define COL1 2
#define ROWS2 COL1
#define COL2 4
#define ROWS3 ROWS1
#define COL3 COL2
main()
{
	int m1[ROWS1][COL1],m2[ROWS2][COL2],m3[ROWS3][COL3],i,j,k;
	for(i=0;i<ROWS1;i++)
	{
		for(j=0;j<COL1;j++)
		{
			printf("enter m1\t");
			scanf("%d",&m1[i][j]);
		}
	}
	for(i=0;i<ROWS2;i++)
	{
		for(j=0;j<COL2;j++)
		{
			printf("enter m2\t");
			scanf("%d",&m1[i][j]);
		}
	}
	/*matrix mul*/
	for(i=0;i<ROWS3;i++)
	{
		for(j=0;j<COL3;j++)
		{
			m3[i][j] = 0;
			for(k=0;k < COL2; k++)
				m3[i][j] += m1[i][k]*m2[k][j];
		}
	}
	printf("displaying m3\n");
	for(i=0;i<ROWS3;i++)
	{
		for(j=0;j<COL3;j++)
		{
			printf("%d\t",m3[i][j]);
		}
		printf("\n");
	}

	
}
