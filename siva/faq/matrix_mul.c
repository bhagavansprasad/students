#include<stdio.h>
#include<math.h>
main()
{
	int i,j,k;
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	int b[3][3]={0,5,0,0,5,0,0,5,0};
	int c[3][3];

	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			c[i][j]=0;
			for(k=0;k<=2;k++)
			{
				c[i][j]=0;
				c[i][j]+=(a[i][k]*b[k][j]);
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

