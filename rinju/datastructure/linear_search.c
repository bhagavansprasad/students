#include<stdio.h>
main()
{
	int i,cnt,arr[10]={1,2,3,4,5,6,7,8,9};
	printf("enter an element to search\n");
	scanf("%d",&cnt);
	for(i=0;i<10;i++)
	{
		if(arr[i]==cnt)
		{
			printf("search element is %d",arr[i]);
		printf("found");
		}
	}
}
