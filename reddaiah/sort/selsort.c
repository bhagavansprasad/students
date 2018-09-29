#include"stdio.h"
main()
{
int i,j,t,n=5,min;
	int a[10]={1,2,5,7,8};
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=0;j<n;j++)
		{
			if (a[min]>a[j])
				min=j;
		}
		if(i!=min)
		{
			t=a[i];
			a[i]=a[min];
			a[min]=t;
		}
	}
	printf("the sorted list is\n");
	for(i=0;i<n;i++)
	{
		printf("%4d\n",a[i]);
	}
}

