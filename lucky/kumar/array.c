#include<stdio.h>
int main()
{
	int a[5]={1,2,3,4,5};
	int b[5]={1,2,3,4,5};
	int c,i,n=5;
	for(i=0;i<=n-1;i++)
	{
		c=a[i]+b[i];
		printf("%d",c);
		printf("\n");
	}
}
