#include<stdio.h>
int main()
{
	int i,j,b,n=5;
	int a[5]={5,4,3,2,1};
	for(i=0;i<=n-1;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			if(a[i]>a[j])
			{
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	for(i=0;i<=n-1;i++)
	{
		printf("%d",a[i]);
	}
}
