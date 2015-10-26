#include<stdio.h>
int main()
{
	int i,j,b,n=5;
	int a[5]={1,6,3,8,4};
	for(i=1;i<n;i++)
	{
		b=a[i];
		for(j=i-1;j>=0&&b<a[j];j--)
		{
			a[j+1]=a[j];
			a[j+1]=b;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
