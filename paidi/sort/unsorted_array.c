#include<stdio.h>
main()
{
int arr[]={10,2,3,22,5,6,23,45,67,32,78};
int i,num=2,n=10;
for(i=0;i<=n;i++)
{
 if(arr[i]==num)
  break;
}
if(i==10)
 
  printf("num not presented array\n");
  else
  printf("num presented array-->=%d\n",i);
 
}
