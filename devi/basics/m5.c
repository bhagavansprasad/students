#include <stdio.h>
int main()
{
int a = 10,b,i;
for(i=0;i<3;i++)
b = my_multi_fun(a);
printf("%d", b);
return 0;
}
int my_multi_fun(int x)
{
int c=20;
x = x*c;
printf("%d\n", x);
return x;
}
