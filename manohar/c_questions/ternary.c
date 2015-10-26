#include <stdio.h>
main()
{
int a=30,b=10,c=20;
int ret=(b>a)?((b>c)?b:c):a;
printf("biggest number:%d\n",ret);
}
