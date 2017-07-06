#include <stdio.h>
main()
{
		int arr[10] = {1,5,7,3,9,10};
		int i ,j,temp,n;
		
		for( i=1; i < 10 ; i++)
		{
					temp= arr[i];
					j=i-1;
					while(j>=0 && temp < arr[j])
					{
					 arr[j+1] = arr[j];
					 j--;
					}
			arr[j+1]=temp;
				}

		
for(i=0;i<10;i++)
printf(" %d ",arr[i]);

}
