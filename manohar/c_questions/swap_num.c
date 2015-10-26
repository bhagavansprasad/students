#include <stdio.h>
int main()
{
int a=10,b=20,temp;
temp=b;
b=a;
a=temp;
printf("a--->%d b---->%d\n",a,b);
return 0;
}
