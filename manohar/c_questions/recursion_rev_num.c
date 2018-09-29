#include <stdio.h>
main()
{
int num=123;
int ret=rev(123);
printf("reverse:%d\n",ret);
}
int rev(int n)
{
int c=0;
if(n!=0)
return (c=(((c*10)+n%10)+rev(n/10)));
}
