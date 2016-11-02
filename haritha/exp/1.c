#include <stdio.h>
main()
{
int i,j;
for(i=1;i<=4;i++)
{
for(j=1;j<=i;j++)
{
printf("%d",j);
}
for(j=i-1;j>=i;i--)
{
printf("%d",j);
}
printf("\n");
}
}
