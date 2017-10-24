#include<stdio.h>
main()
{
int i=0,a=0,m=2;
while(i<=(sizeof(int)/2)*8)
{
a=a<<2;
a=a|m;
i=i+2;
}
printf("%d",a);
}

