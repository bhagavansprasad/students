#include<stdio.h>
main()
{
int a=0x12131415;
short *sh=&a;
sh=sh+1;
printf("sh1=%x\n",*(sh-0));
printf("sh2=%x\n",*(sh-1));
}
