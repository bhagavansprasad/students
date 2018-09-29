/* Linear Search in Array */

#include<stdio.h>

int main()
{
 int arr[10],i,value,index;
 printf("Please enter 10 values:\n");
 for(i=0;i<10;i++)
  scanf("%d",&arr[i]);
  
 printf("\nEnter a value to be searched: ");
 scanf("%d",&value);
 
 index = -1;
 for(i=0;i<10;i++)
 {
  if(arr[i]==value)
  {
   index=i;
   break;
  }
 }
 
 if(index>=0)
  printf("Value found in Array at %d location",index);
 else
  printf("Value not found in Array");
 return 0;
}
