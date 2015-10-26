#include<stdio.h>
main()
{
	int i,j,t;
	int a[5]={9,6,2,8,4};
	for(i=0;i<=4;i++)
	{
		printf("%d",a[i]);
		printf("\n");
	}
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=5-i-2;j++)
		{
			if(a[i]<a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	printf("ascending order is");
	for(i=0;i<=4;i++)
	{
		printf("%d",a[i]);
		printf("\n");
	}
}

