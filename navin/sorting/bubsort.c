#include <stdio.h>
void bubsort(int arr[],int n);

main()
{
	int arr[10]={1,3,4,0,6,3},i;
//	int n=6;
	bubsort(arr,6);

	printf("Sorted array :");

	for(i=0;i<6;i++)
		printf(" %d",arr[i]);
	printf("\n");
}


void bubsort(int arr[],int n)
{
	int i,j,temp;

	for(i=0;i<(n-1);++i)
	{
		for(j=0;j<n-i-1;++j)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			} 
		}
	}		  



}
