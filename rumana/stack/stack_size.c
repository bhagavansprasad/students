#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE \
register int sp asm ("sp");\
register int ebp asm("ebp");\
printf("stack size :%u\n",ebp-sp);\

//#define PRINT_VAL(x)  (printf("var is %s\t and val is %d\n",#x,x))
#define PRINT_ADDR(x) (printf("var is %s\t and val is %u\n",#x,&x))

int fun1(int,int);

main()
{
int a=10,b=20;
//PRINT_VAL(a);
//PRINT_VAL(b);
PRINT_ADDR(b);
PRINT_ADDR(a);
fun1(a,b);
}


int fun1(int x,int y)
{
int c=10,d=20,i=30,r=40,m=50;
PRINT_ADDR(m);
PRINT_ADDR(r);
PRINT_ADDR(i);
PRINT_ADDR(d);
PRINT_ADDR(c);
PRINT_ADDR(x);
PRINT_ADDR(y);
STACK_SIZE;
printf("ebp is %u\n",ebp);
printf("sp is %u\n",sp);
printf("a value is %u\n",ebp+24);
printf("m value is %u\n",ebp-4);
printf("y value is %u\n",ebp-40);

//fun2(c,d);
}


/*int fun2(int s,int t)
{
int e=10,f=20;
PRINT_ADDR(f);
PRINT_ADDR(e);
PRINT_ADDR(s);
PRINT_ADDR(t);
}*/
