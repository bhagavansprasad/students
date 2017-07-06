#include<stdio.h>
//#include<alloc.h>
main()
{
	int i,j,row=4,col=4;
	int **p=(int **)malloc(row*sizeof(int*));
	for(i=0;i<row;i++)
	{
		p[i]=(int*)malloc(col*sizeof(int));
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			*(*(p+i)+j)=i*2+j;
		}
	}

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d",*(*(p+i)+j));
		}
	printf("\n");
	}
	printf(" a[1][1]=%d ",*(*(p+1)+1));
}


