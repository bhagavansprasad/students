#include <stdio.h>
main()
{
int i,j,t,n=6,min;
int a[10]={8,1,7,6,4,2};
for(i=0;i<n;i++)
{ 
  min=i;
  for(j=i+1;j<n;j++)
  if(a[10]<a[min])
  min=j;
	  t=a[i];
	  a[i]=a[min];
	  a[min]=t;
	 }
	
	printf("the sorted list is");
	for(i=0;i<n;i++)
	{
	  printf("%5d\n",a[i]);
	 }
	 return 0;
}
