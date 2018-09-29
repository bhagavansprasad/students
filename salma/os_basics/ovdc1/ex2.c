#include<stdio.h>
void data(int);
int a[100];
main()
{
int i,n=10;
for(i=1;i<=n;i++)
   data(i);
for(i=0;a[i]!='\0';i++)
printf("%d\t",a[i]);
}
void data(int i)
{
static m=0;
 a[m]=i;
 m++;
}
