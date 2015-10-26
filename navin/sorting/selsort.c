#include <stdio.h>
void selsort(int arr[],int n);

main()
{
	int arr[10]={1,5,4,0,2,3},i;
//	int n=6;
	selsort(arr,6);

	printf("Sorted array :");

	for(i=0;i<6;i++)
		printf(" %d",arr[i]);
	printf("\n");
}


void selsort(int arr[],int n)
{
	int i;
	for(i=0;i<n-1;++i)
	{
    int  j,temp,min;

	min=i;

	  for(j=i+1;j<n;++j)
		{   		   
		    
			
			if(arr[j]<arr[min])
		       min=j;
		
		}
                temp=arr[i];
				arr[i]=arr[min];
				arr[min]=temp;


	}		  



}
