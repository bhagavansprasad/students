#include <stdio.h>

main()
{
 int a = 0x12131415;
 short int *sp = &a;

 printf("-->sh1 : %x\n", *sp);
 printf("-->sh2 : %x\n", *(sp+1));
}
