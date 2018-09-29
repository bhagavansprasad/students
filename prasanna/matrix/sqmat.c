#include<stdio.h>

int main()
{
	int a[3][3], i, j;


	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i == 0 && j == 1)
				a[i][j] = 1;
			else if(i == 2 && j == 2)
				a[i][j] = 2;
			else if(i == 1 && j ==0)
				a[i][j] = 3;					
			else if(i == 2 && j ==0)
				a[i][j] = 4;	
			else if(i == 1 && j ==1)
				a[i][j] = 5;	
			else if(i == 0 && j ==2)
				a[i][j] = 6;	
			else if(i == 1 && j ==2)
				a[i][j] = 7;	
			else if(i == 0 && j ==0)
				a[i][j] = 8;	
			else 
				a[i][j] = 9;
		}
	}
	for(i =0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",a[i][j]);
		}
	printf("\n");
	}	
}


