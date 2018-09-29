#include<stdio.h>
#define MAX 2
main()
{
int i,n=7;
int r;
r=prime(n);
if(r==0)
printf("prime\n");
else
printf("not prime\n");
}

prime(int j)
{
int r,i;
for(i=MAX;i<j;i++)
{
if(j%i==0)
{
r=1;
break;
}
}
if(i== j)
r=0;
return r;
}
