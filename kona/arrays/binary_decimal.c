#include<stdio.h>
main()
{
int a=1010,c,d,s=0,p=1;
while(a!=0)
{
c=a%10;
d=c*p;
p=p*2;
s=s+d;
a=a/10;
printf("%d", s);
}
}

