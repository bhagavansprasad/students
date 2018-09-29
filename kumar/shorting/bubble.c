#include<stdio.h>
int main()
{
	int i,j,k,t,n=5,a[5]={33,88,66,77,11};
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
			}
		}
	}
	printf("%d",t);
	for(k=0;k<n;k++)
	{
		printf("%d\n",a[k]);
	}

}
