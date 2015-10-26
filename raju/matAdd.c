#include<stdio.h>
main()
{
	int m=2,n=2,i,j;
	int a[2][2]={{2,5},{3,4}},b[2][2]={{6,9},{7,8}},c[m][n];
	
	
/*	printf("Enter number of rows\n");
	scanf("%d",&m);
	printf("Enter number of columns\n");
	scanf("%d",&n);
	printf("Enter elements of matrix a\n");
	for(i=0;i<m;i++)
	{
	  for(j=0;j<n;j++)
	  {
	    scanf("%d",&a[i][j]);
	  }
	}
	printf("Enter elements of matrix b\n");
	for(i=0;i<m;i++)
	{
	  for(j=0;j<n;j++)
	  {
	    scanf("%d",&b[i][j]);
	  }
	}                          */
	for(i=0;i<m;i++)
	{
	  for(j=0;j<n;j++)
	  {
	    c[i][j]=a[i][j]+b[i][j];
	  }
	}
	printf("Elements of matrix c\n");
	for(i=0;i<m;i++)
	{
	  for(j=0;j<n;j++)
	  {
	    printf("%d\t",c[i][j]);
	  }
	  printf("\n");
	}
}	


