#include <stdio.h>
main()
{
	int i,j,temp,n=8,min,a[22]={12,4,59,85,24,15,3,65};
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			min=j;
		}
		if(i!=min)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	printf("the sorting elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
}
