#include <stdio.h>
main()
{
int i,k,j,n=5;
for(i=1;i<=n;i++)
{
for(j=n-i;j>=1;j--)
{
printf(" ");
}
for(k=1;k<=i;k++)
{
printf("%d",k);
}
printf("\n");
}
}

