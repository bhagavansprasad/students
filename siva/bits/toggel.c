#include<stdio.h>
main()
{
int n,pos;
toggle(4,2);
}
void toggle(int n,int pos)
{
int k,mask;
k=1<<pos;
mask=n^k;
if(mask==0)
printf("0");
else
printf("1");
}

