#include<stdio.h>
main()
{
int a[5]={0,2,1,4,3};
int i,n,j,t;
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4-i;j++)
		{
			if (a[i]>a[j+1])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
					printf("%d",a[j]);
			}		
		}
	}
}

