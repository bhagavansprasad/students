#include<stdio.h>
main()
{
  int i,j,k,n=5;
  for(i=1; i<=n;i++)
  {
   for(j=1;j<=i;j++)
      printf(" %d ", j);
   for(k=i;k<=n;k++)
       printf(" - ");
   printf("\n");
 }
}
