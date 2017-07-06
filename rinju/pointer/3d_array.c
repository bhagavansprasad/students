#include<stdio.h>
//#include<alloc.h>
main()
{
	int i,j,k,row=4,col=4;
	int ***p=(int ***)malloc(row*sizeof(int**));
	for(i=0;i<row;i++)
	for(j=0;j<col;j++)
	{
		p[i][j]=(int**)malloc(col*sizeof(int*));
	}
	for(i=0;i<row;i++)
	for(j=0;j<col;j++)
	for(k=0;k<col;k++)
	{
		p[i][j][k]=(int)malloc(col*sizeof(int));
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
		for(k=0;k<col;k++)
		{
			*(*(*(p+i)+j)+k)=i*2+j;
		}}
	}

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{for(k=0;k<col;k++)
		{
			printf("%d",*(*(*(p+i)+j)+k));
		}}
	printf("\n");
	}
	printf(" a[1][1]=%d ",*(*(p+1)+1));
}


