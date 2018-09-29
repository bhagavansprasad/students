#include <stdio.h>
main()
{
 int n=5,m=5,i,j,k,l;
 int a=0;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=m;j++)
  printf("%d",j);
  for(k=1;k<=((2*a)-1);k++)
  printf(" ");
  for(l=m;l<=m;l--)
  {
   if(l==5)
   {
   printf("");
   }
   else
   printf("%d",l);
  }
  printf("\n");
  a++;
  m--;
 }
} 
   
