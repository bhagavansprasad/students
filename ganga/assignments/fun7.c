#include <stdio.h>
//#include <defs1.h>
extern int b;
extern int a;
#define MAX 5
void my_function1(void)
{
 printf("-->MAX :%d\r\n", MAX);
 printf("-->b :%d\r\n", b);
}


extern int a;

void my_function2(void)
{
 printf("-->MAx :%d\r\n", MAX);
 printf("-->a :%d\r\n", a);
 printf("-->b :%d\r\n", b);
}

