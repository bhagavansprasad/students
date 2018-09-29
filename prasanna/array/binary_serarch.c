/* Binary Search */

#include<stdio.h>

int main()
{
 int arr[10],i,max,min,mid,val,index;

 printf("Please enter 10 values in ascending order:\n");
 for(i=0;i<10;i++)
  scanf("%d",&arr[i]);
 
 printf("\nEnter a value to be searched: ");
 scanf("%d",&val);
 
 max=9;
 min=0;
 index=-1;
 while(min<=max)
 {
  mid=(max+min)/2;
  if(val==arr[mid])
  {
   index=mid;
   break;
  }
  if(arr[mid]>val)
   max=mid-1;
  else
   min=mid+1;
 }
 
 if(index>=0)
  printf("Value found in Array at %d location",index);
 else
  printf("Value not found in Array");
 return 0;
}
