#include<stdio.h>
main()
{
int n=5;
int result;
result = factorial(n);
printf("factorial value is %d",result);
}

 factorial( int k)
{ int f=1,a=1,i;
for(i=1;i<=k;i++)
{
f=f*a;
a++;
}
return f;
}
