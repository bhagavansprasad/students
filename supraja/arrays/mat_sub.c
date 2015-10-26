#include <stdio.h>
int main()
{
	int a[2][2]={
		{5,6},
		{7,8}
	} ;
	int b[2][2]={
		{1,2},
		{3,4}
	};
	int c[4];
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			c[i]=a[i][j]-b[i][j];
			printf("%d\n",c[i]);
		}
	}
}	
