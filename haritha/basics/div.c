#include<stdio.h>
main()
{
int i,j,fact=1,fact1=1,n=2,s=0,count=5,t=0;
for(i=2;i<=n;i++)
while(t<count)
{

fact=i*fact;
printf("i-->%d\n",fact);
}
for(j=1;j<=i-1;j++)
{
fact1=j*fact1;
}
printf("j-->%d\n",fact1);

if((fact/fact1)!=0)
printf("i/j-->%d\n",fact/fact1);
s=s+(fact/fact1);
printf("s-->%d\n",s);
t++;
printf("t-->%d",t);
}
n++;
}
