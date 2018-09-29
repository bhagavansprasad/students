#include <stdio.h>
main()
{
int i,j,n=5,t,sp;
sp=n-1;
for(i=1;i<=n;i++)
{
if(i<n)
{
for(j=sp;j>=1;j--)
printf(" ");
sp--;
}
for(j=1;j<=i;j++)
printf("%d",j);
printf("\n");
}
}
