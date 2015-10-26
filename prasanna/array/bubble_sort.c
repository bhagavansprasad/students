/* Bubble Sort */

#include<stdio.h>


int main()
{
 int arr[10],i,j,t;
 printf("Please enter 10 values:\n");
 for(i=0;i<5;i++)
  scanf("%d",&arr[i]);
 
 for(i=0;i<5;i++)
 {
  for(j=0;j<(5-i-1);j++)
  {
   if (arr[j]>arr[j+1])
   {
    t=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=t;
   }
  }
 }
 
 printf("Sorted Array is:\n");
 for(i=0;i<5;i++)
  printf("%d\n",arr[i]);
 
 return 0;
}

