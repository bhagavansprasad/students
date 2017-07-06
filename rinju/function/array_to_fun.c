#include<stdio.h>
int fun(int *a)
{
int i;
	for(i=0;i<5;i++)
	{
		printf(" %d ",*(a+i));
		*(a+i)=*a+4+i;
	}
	printf("\n");
}
main()
{
	int i,arr[]={1,8,24,56,5};
	fun(arr);
	for(i=0;i<5;i++)
	{
		printf(" %d ",arr[i]);
	}
}
