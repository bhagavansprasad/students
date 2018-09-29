#include <stdio.h>
main()
{
	int a[39][39]={0};
	int n=15,i,j,num;
	i=n-1;
	j=(n-1)/2;
	for(num=1;num<=n*n;num++)
	{
		a[i][j]=num;
		i++;
		j--;
		if(num%n==0)
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
			printf("%8d",a[i][j]);
		printf("\n");
	}
}

