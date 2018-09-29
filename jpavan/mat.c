#include<stdio.h>
main()
{
int i,j,k;
int
a[3][3]={{1,2,3},{4,5,6},{1,2,3}},b[3][3]={{4,5,6},{1,2,3},{1,2,3}},c[3][3]={{0,0,0},{0,0,0},{0,0,0}};
for(i=0;i<=2;i++)
	{
	 for(j=0;j<=2;j++)
	 	{
		 printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
for(i=0;i<=2;i++)
	{
	 for(j=0;j<=2;j++)
	 	{
		 printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
for(i=0;i<=2;i++)
	{
	 for(j=0;j<=2;j++)
	 	{
		for(k=0;k<=2;k++)
	 	{

		c[i][j]= c[i][j]+(a[i][k]*b[k][j]);
	
		 }
		}
	}
		for(i=0;i<=2;i++)
		{
		 for(j=0;j<=2;j++)
		 	{
			printf("%d\t",c[i][j]);
			}
		printf("\n");
		}

}

