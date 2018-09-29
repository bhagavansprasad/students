#include<stdio.h>
int main()
{
int a=10;
int b=20;
int c=0;
c=(a&b);
printf ("%d\n",c);
c=(a|b);
printf("%d\n",c);
c=~b;
printf("%X\n",c);
c=(a<<2);
printf("%d\n",c);
c=(a>>2);
printf("%d\n",c);
}
