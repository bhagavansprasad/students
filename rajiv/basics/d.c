#include <stdio.h>
main()
{
 int a=0,b=1,c,n=10,i;
 for(i=1;i<=n;i++)
 {
 c=a+b;
 printf("sum is %d \n",c);
 a=b;
 b=c;
 }
} 

