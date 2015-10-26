#include <stdio.h>
main()
{
int n=5,m=5,i,j;
for(i=1;i<=5;i++)
{
 for(j=1;j<=i-1;j++)
 printf(" ");
 for(j=1;j<=m;j++)
 {
  printf("%d",j);
 }
 printf("\n");
 m--;
} 
}
