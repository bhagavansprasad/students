#include<stdio.h>
#include<stdlib.h>
# define size 5
void main()
{
	int n=size;
	int i=0,j=n/2;
	int k;
	int a[size][size]={0};
	
	for(k=1;k<=n*n;k++)
	{
		a[i][j]=k;
		i--;
		j++;
		
		if(k%n==0) 
		{
			i=i+2;
			j--;
		}
		
		else
		{
			if(j==n)
				j=j-n;
			else if(i<0)
				i=i+n;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n\n");
	}
	
}
