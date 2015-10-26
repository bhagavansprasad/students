#include<stdio.h>
main()
{
int n=500,x=0,i,a=0;
for(i=1;i<=n;i++)
{
x=is_arm(i);
if(x==1)
{
a=a+i;
printf("%d \n",a);
}
}
}
int is_arm(int i)
{
int j,t,r,s=0;
t=i;
for(j=1;j<=3;j++)
{
r=i%10;
i=i/10;
s=s+(r*r*r);
}
if(s==t)
return (1);
else
return (0);
}
