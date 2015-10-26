#include <stdio.h>
main()
{
 int n=5,k=1,i,j;
 for(i=1;i<=5;i++)
 {
  for(j=1;j<=n-i;j++)
  printf(" ");
  for(j=1;j<=k;j++)
  {
  printf("%d",j);
  }
  printf("\n");
  k++;
 }
} 
