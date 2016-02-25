#include <stdio.h>
main()
{
	int a[10]={1,43,67,44,90,78,46,98,24,53};
	int n=10,i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	printf("the array elements is %d\n",a[i]);
	printf("the second largest element is %d\n",a[n-2]);

}
