#include<stdio.h>
int main()
{
	int a[5]={1,3,2,4};
	int i,j,b,n=5;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
