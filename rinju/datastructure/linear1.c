#include<stdio.h>
main()
{
	int arr[5]={1,2,3,4,5};
	int flag=0,i,cnt;
	printf("enter a element to search");
	scanf("%d",&cnt);
	for(i=0;i<5;i++)
	{
		if(arr[i]==cnt)
		{
			flag=1;
			break;
		}
	}
if(flag==1)
printf("found");
else
printf("not found");
}
