#include <stdio.h>
main()
{
 int a=426;
 int b,c,sum=0;
 c=a%10;
 b=a/10;
 sum=sum+c;
 c=b%10;
 b=b/10;
 sum=sum+c;
 c=b%10;
 b=b/10;
 sum=sum+c;
}
