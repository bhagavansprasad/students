#include <stdio.h>

main()
{
 int num=1010;
 int i=0,c,n=1;
 for(i=0;i>=num;i--)
 {
  c=c+num*n;
  n=n*2;
 }
 printf("c::::%h\n",c);
}
