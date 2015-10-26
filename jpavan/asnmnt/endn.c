#include <stdio.h>
main()
{
int a=0x12131415;
char *ch=&a;
printf("ch1 value at adress %u =%x\n",(ch+0),*(ch+0));
printf("ch2 value at adress %u =%x\n",(ch+1),*(ch+1));
printf("ch3 value at adress %u =%x\n",(ch+2),*(ch+2));
printf("ch4 value at adress %u =%x\n",(ch+3),*(ch+3));
}
