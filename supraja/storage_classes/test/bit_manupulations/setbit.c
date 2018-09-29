#include<stdio.h>
int main()
{
int a=10,c;
int pos=4;
unsigned int mask=1<<(pos-1);
c=a&mask;
if(c==0)
printf("0\n");
else
printf("1\n");
}
