#include<stdio.h>
int main()
{
	int a[3][3];
	int i,j,k,n=3;
	i=n-3;
	j=(n-1)/2;
	for(k=1;k<=n*n;k++)
	{
		a[i][j]=k;
		i--;
		j++;
	if(k%n==0)
	{
		i+=2;
		j--;
	}
		else if(i==-1)
			i=n-1;
		else if(j==n)
			j=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
