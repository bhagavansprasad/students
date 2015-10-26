#include<stdio.h>
main()
{
 int i,j,temp,n=7,arr[20]={5,6,3,2,7,8,9};
 for(i=0; i<n; i++)
 {
   for(j=0; j<(n-1)-i; j++)
   {
     if( arr[j] > arr[j+1] )
     {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
     }
   }
   }
   printf("%d\t",arr[j]);
 for(i=0;i<n;i++)
 {
 printf("%d\n",arr[i]);
 }
 }
