#include<stdio.h>
main()
{
int a=426,s=0;
s=s+a%10;
a=a/10;
s=s+a%10;
a=a/10;
s=s+a%10;
printf("%d",s);
}
