#include <stdio.h>
int main()
{
int a=-1,b=1,c,i,n=7,sum=0;
for(i=1;i<=n;i++)
{
c=a+b;
sum=sum+c;
a=b;
b=c;
}
printf("sum of fibonacci:%d\n",sum);
}

