#include"stdio.h"
#include"sys/resource.h"
main()
{
int y,prior_val;
int which;
y=getpriority(which,19327);
printf("return value before setting:%d \r\n",y);
y=y+5;
prior_val=setpriority(which,19327,y);
printf("return value after setting:%d\r\n",prior_val);
}
