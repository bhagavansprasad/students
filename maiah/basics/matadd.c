#include <stdio.h>
#define x 3
#define y 3
main()
{
	int a[x][y]={0},b[x][y]={0},c[x][y]={0};
	int i,j;
	printf("enter the matrix a");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
			scanf("%d",&a[x][y]);
	}
	printf("enter the matrix b");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
			scanf("%d",&b[x][y]);
	}
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			c[x][y]=a[x][y]+b[x][y];
		}
	}
	printf("the resulant matric c[x][y]:\n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
			printf("%5d",c[x][y]);
		printf("\n");
	}
	return(0);
}
