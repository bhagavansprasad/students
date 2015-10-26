#include<stdio.h>
void swapv(short int* sh1,short int* sh2);
main()
{
int a=0x12131415;
short int *sh1=(short int *) &a;
short int *sh2;//=(short int *) &a;
sh2=sh1+1;

swapv(sh1,sh2);

printf("%x\n",*sh1);
printf("%x\n",*sh2);
}
void swapv(short int* sh1,short int* sh2)
{
short int * t;

t = sh1;
sh1 = sh2;
sh2 = t;
}

