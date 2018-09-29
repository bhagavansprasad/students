#include<stdio.h>
int main()
{
	int a[5]={4,9,2,1},b;
	int i,j,n=5;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
