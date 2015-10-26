#include<stdio.h>
main()
{
int i=-5;
showbits(5);
}
void showbits(int n)
{
int mask,i;
for(i=7;i>=0;i--)
{
mask=n&(1<<i);
if(mask==0)
printf("o");
else
printf("1");
}
}
