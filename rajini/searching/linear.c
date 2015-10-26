#include <stdio.h>
main()
{
int arr[100],search,c,n;
printf("enter the no. of elements in array\n");
scanf("%d",&n);
printf("enter %d integers \n",n);
for(c=0;c<n;c++)
scanf("%d",&arr[c]);
printf("enter the no.to search\n");
scanf("%d",&search);
for(c=0;c<n;c++)
{
  if(arr[c]==search)
    {
	  printf("%d is present at location %d\n",search,c+1);
	  break;
	  }
}
if(c==n)
printf("%d is not present in arr.\n",search);
return 0;
}

