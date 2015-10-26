#include <stdio.h>
main()
{
 int arr[]={0,1,2,3,4,};
 unsigned int i;
 int *p;
 for(p=arr+4,i=0;i<=4;i++)
 printf("revese--->= %d\n",p[i]);
}
