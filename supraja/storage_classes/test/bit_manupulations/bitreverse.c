#include <stdio.h>
int main()
{
int i,a=10,c;
for(i=0;i<=7;i++)
{
c=a&(1<<i);
c==0?printf("0"):printf("1");
printf("\n");
}
}
