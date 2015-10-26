#include <stdio.h>
main()
{
	int a[12]={12,18,4,6,3,55,14,1},i,j,n=8,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("sorted list is :\n");
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
}
