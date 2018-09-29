#include<stdio.h>
int main()
{
	int i,j,n=5,temp;
	int a[5]={6,8,1,4,2};
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;temp<a[j]&&j>=0;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
	for(i=0;i<n;i++)
		printf(" %d",a[i]);
}
