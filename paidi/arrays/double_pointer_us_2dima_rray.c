#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j,k,count=0;
	int r=3,c=4;
	printf(" Enter Rows and Cols for 2D array: \n");
	//scanf("%d %d",&r,&c);

	int **arr;
	arr = malloc(r * sizeof(int ));

	for(i=0;i<r;i++)
		arr[i] = malloc(c * sizeof(int ));

	for(j = 0;j<r;j++)
		for(k = 0;k < c;k++)
			arr[j][k] = count++;

	for(j = 0;j<r;j++)
	{
		for(k=0;k<c;k++)
			printf(" |%2d|", arr[j][k]);
		printf("\n");
	}
}

