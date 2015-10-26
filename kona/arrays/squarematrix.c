#include <stdio.h>
//#define MAX 20
main()
{
	int a[5][5]={95,67,32,35,44,12,11,16,93,29,82,13,21,31,27,24,18,28,15,33,39,30,26,23,34};
	int n=5,i,j,start,end;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%5d",a[i][j]);
		printf("\n");
	}
	for(start=0,end=n-1;start<=end;start++,end--)
	{
		for(i=start;i<=end;i++)
		printf("%d",a[start][i]);
		for(i=start+1;i<=end;i++)
		printf("%d",a[i][end]);
		for(i=end-1;i>=start;i--)
		printf("%d",a[end][i]);
		for(i=end-1;i>=start+1;i--)
		printf("%d",a[i][start]);
	}
	return 0;
}
