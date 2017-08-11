#include<stdio.h>
main()
{
	int i;
	int arr[]={1,2,3,4,5};
	//p=arr;
	int (*p)[5]=arr;
	for(i=0;i<5;i++)
	{
		//(*p)[i]=i+2;
		printf(" %d ",(*p)[i]);
		
	}
	printf(" %d ",sizeof(*p));
	printf(" %d ",sizeof(p));
	printf(" %d ",sizeof(arr));
}
