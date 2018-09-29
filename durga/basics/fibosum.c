#include<stdio.h>
main()
{
int s=0, n1=0,n2=1,n3,count=0,n=7;
 while(count<=n)
 {
   n3=n1+n2;
   n1=n2;
   n2=n3;
   s+=n3;
   count++;
   printf("\t%d",n3);
   }
   printf("sum=%d",s);
   return(0);
}
