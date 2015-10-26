#include<stdio.h>
int main()
{
	int a[7][7];
	int i,j,k,n=7;
	i=n-1;
	j=(n-1)/2;
	for(k=1;k<=n*n;k++)
	{
		a[i][j]=k;
		i++;
		j--;
		if(k%n==0)
		{
			i-=2;
			j++;
		}
		else if(i==n)
			i=0;
		else if(j==-1)
			j=n-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
