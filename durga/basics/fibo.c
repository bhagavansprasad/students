#include<stdio.h>
main()
{
 int n1=0,n2=1,n3,count=0,n=5;
 printf("%d\t%d",n1,n2);
 while(count<n)
 {
   n3=n1+n2;
  n1=n2;
  n2=n3;
  printf("\t %d",n3);
  count++;
 }
  return(0);

}
