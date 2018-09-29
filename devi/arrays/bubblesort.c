#include<stdio.h>
main()
{
	int i,j,t;
	int a[5]={8,4,6,1,2};
	for(i=0;i<5;i++)
		printf("%d\t",a[i]);
		printf("\n");
		for(j=0;j<5;j++)
		{
			for(i=0;i<5;i++)
			{
				if(a[i]>a[i+1])
				{
					t=a[i];
					a[i]=a[i+1];
					a[i+1]=t;
				}
				printf("%d \t",a[i]);
			}
			printf("\n");
		}
		for(i=0;i<5;i++)
		printf("%d\t",a[i]);
		printf("\n");
}
