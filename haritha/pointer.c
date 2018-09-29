#include<stdio.h>
main()
{
int a=0x12131415,i,j=2,b=0;
char *cp=(char *)&a;
for(i=0;i<=3;i++)
{
cp=(char *)&a+i;
if(i==j)
printf("%x",b);
else
printf("%x",*cp);
}
}

