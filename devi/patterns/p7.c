#include <stdio.h>
main()
{
int i,j,sp,n=5;
sp=n+(n-1);
for(i=1;i<=n;i++)
{
for(j=1;j<=i;j++)
printf("%d",j);
if(i<n)
{
sp=sp-2;
for(j=sp;j>=1;j--)
printf(" ");
}
for(j=i;j>=1;j--)
if(j!=n)
printf("%d",j);
printf("\n");
}
}
