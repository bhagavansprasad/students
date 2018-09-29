#include <stdio.h>
main()
{
	int a[5]={44,33,55,22,11},i,j,temp;
	for(i=0;i<=3;i++)
	{
		for(j=i+1;j<=4;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<=4;i++)
	{
		printf("%d\n",a[i]);
	}
	}
