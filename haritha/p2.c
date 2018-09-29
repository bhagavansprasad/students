#include<stdio.h>
main()
{
int a=500,i;
char *p=&a;
for(i=3;i>=0;i--)
{
printf("%d",*(p+i));
}
}
