#include<stdio.h>
main()
{
int arr[10]={1,4,10,2,3,56};
int i,pivot,start=0,end=10,temp;
pivot=arr[0];
for(i=0;i<10;i++)
{
while(1)
{
 		while(arr[start]< pivot && arr[start]!= pivot)
		start++;
		while(arr[end]>pivot && arr[end]!=pivot)
		end--;
		if(start < end)
		{
				temp = arr[start];
				arr[start] = arr[end];
				arr[end]= temp;
		}
		else return end;
}

}

for(i=0;i<10;i++)
printf(" %d ",arr[i]);
}
