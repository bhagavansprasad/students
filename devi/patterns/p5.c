#include <stdio.h>
main()
{
int j,i,n=5,t,sp;
t=n;
for(i=0;i<n;i++)
{
sp=i;
if(sp>0)
{
for(j=sp;j>=1;j--)
printf(" ");
}
for(j=1;j<=t;j++)
{
printf("%d",j);
}
printf("\n");
t--;
}
}
