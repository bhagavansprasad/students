#include<stdio.h>
int main()
{
	int i,j,n=5,b;
	int a[5]={5,4,3,2,1};
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if(a[i]>a[j+1])
			{
				b=a[i];
				a[i]=a[j+1];
				a[j+1]=b;
			}
			printf("%d",a[5]);
		}
		printf("\n");
	}
}

