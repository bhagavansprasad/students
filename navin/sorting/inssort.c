#include <stdio.h>
void inssort(int arr[],int n);

main()
{
	int arr[10]={1,5,4,0,2,3},i;
//	int n=6;
	inssort(arr,6);

	printf("Sorted array :");

	for(i=0;i<6;i++)
		printf(" %d",arr[i]);
	printf("\n");
}


void inssort(int arr[],int n)
{
	int i,j,index;

	for(i=1;i<n;++i)
	{
	  
      index	=arr[i];

	  for(j=i;j>0&&arr[j-1]>index;j--)
	 		 arr[j]=arr[j-1];  
		    
			arr[j]=index;
	     
				
	}		  



}
