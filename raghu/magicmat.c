#include <stdio.h>
main()
{
	int n=5,i,j,k,a[n][n];
	i=5-1;
	j=5/2;
	for(k=1;k<=(n*n);k++)
	{
		if(a[i][j]==0);
	//	printf(" a[%d][%d]--->%d",i,j,k);
		else
		{
			i=i-2;
			if(i<0)
			i=n-i;
			j++;
			if(j==5)
			j=0;
			//printf(" a[%d][%d]--->%d",i,j,k);
		}
		printf(" a[%d][%d]--->%d",i,j,k);
		i++;
		if(i==5)
		i=0;
		j--;
		if(j<0)
		j=n-1;
		}
		printf("\n");
}
