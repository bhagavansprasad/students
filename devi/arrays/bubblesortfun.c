#include<stdio.h>
main()
{
	int i,t;
	int a[5]={8,4,6,1,2};
//	printf("%u %u",&a,&p);
	for(i=0;i<5;i++)
		printf("%d\t",a[i]);
	printf("\n");
	bubblesort(a,5);
	for(i=0;i<5;i++)
		printf("%d\t",a[i]);
}
int* bubblesort(int *a,int r)
{
	int i,t;
	for(i=0;i<r;i++)
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
