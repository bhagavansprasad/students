#include<stdio.h>
int main()
{
	int i,j;
	int c[2][2];
	int a[2][2]={{1,2},{2,1}};
	int b[2][2]={{1,2},{2,1}};
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	for(i= 0; i< 2; i++)
	{
	for(j=0;j<2;j++)
	{
		printf("%d\t",c[i][j]);
		
	}
	printf("\n");
}	
}
