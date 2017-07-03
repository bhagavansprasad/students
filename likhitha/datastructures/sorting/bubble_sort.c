#include<stdio.h>
main()
{
	int a[7]={7,2,8,3,1,6,4};
	int i , j , n=7 ,temp=0;
	for(i=0 ; i<n ; i++)
	{
		for(j=0 ; j< n; j++)
		{
			if(a[j]>a[j + 1])
			{
				temp=a[j];
				a[j]=a[j + 1];
				a[j + 1]=temp;
			}
		}
	}
	printf("sorted array is-->");
	for( j = 0; j< n; j++)
	{
		printf("%d ",a[j]);
	}
	printf("\n");
}
