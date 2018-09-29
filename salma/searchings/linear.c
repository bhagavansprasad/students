#include<stdio.h>
#define MAX 60
int linearsearch(int *,int,int);
main()
{
	int arr[MAX],index,item,n,i;
	printf("\nenter range of an array elements:");
	scanf("%d",&n);
	printf("\n enter %d no of elements for an array :",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\nenter the element to be searched:");
	scanf("%d",&item);
	index=linearsearch(arr,item,n);
	if(index==-1)
		printf("element not found\n");
	else 
		printf("element found at %d postion",index);
}
int linearsearch(int arr[],int item,int n)
{
	int i=0;
	while(i<n && arr[i]!=item)
		i++;
	if(i<n)
		return i;
	else 
		return -1;

}
