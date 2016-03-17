#include <stdio.h>
main()
{
int i,s,j,n=5;
for(i=n;i>=1;i--)
{
for(s=i;s<=4;s++)
{
printf(" ");
}
for(j=1;j<=i;j++)
{
printf("%d",j);
}
printf("\n");
}
}
