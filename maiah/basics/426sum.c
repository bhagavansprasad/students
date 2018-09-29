#include<stdio.h>
main()
{
int a=426,sum=0,c;
c=a%10;
sum=sum+c;
a=a/10;
c=a%10;
sum=sum+c;
a=a/10;
c=a%10;
sum=sum+c;
printf("%d\n",sum);
}
