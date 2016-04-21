#include<stdio.h>
main()
{
	int i,j,m,n,a[10][10],b[10][10],c[10][10];
	printf("enter rows and columns of a matrix");
	scanf("%d%d",&i,&j);
	{
		printf("enter the elements in first matrix");
	    {
		for(m=0;m<i;m++)
			for(n=0;n<j;n++)
			scanf("%d",&a[m][n]);
			}
	printf("enter the elements in second matrix");
	{
		for(m=0;m<i;m++)
			for(n=0;n<j;n++)
			scanf("%d",&b[m][n]);
	}
	for(m=0;m<i;m++)
		for(n=0;n<j;n++)
		c[m][n]=a[m][n]+b[m][n];
		printf("sum is %d",c[m][n]);
	}printf("\n");
	return 0;
}

