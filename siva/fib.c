
#include<stdio.h>
main()
{
int a,b=1,c;
int n=6,i,sum=0;
a=(-1);
for(i=1;i<=n;i++)
{
c=a+b;
a=b;
b=c;
sum=sum+c;
printf("%d\n",c);
}
printf("sum is = %d\n",sum);
}
