/* 1 2 3 4 5 4 3 2 1 */
#include<stdio.h>
main()
{
int i,n=5;
for(i=1;i<=n;i++)
{
printf("%d",i)
}
printf("first loop ended\n");
for(;i<=1;i--)
{
printf("%d",i);
}
printf("2nd loop ended\n");
}

