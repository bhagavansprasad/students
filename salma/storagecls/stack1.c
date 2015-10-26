#include<stdio.h>
#define PRINT_VAL(x)  (printf("%10u\n",&x))
void fun1(int,int);
void fun2(int,int);
void fun3(int,int);
main()
{
int a=10,b=20;
PRINT_VAL(a);
PRINT_VAL(b);
fun1(a,b);
}
fun1(int x, int y)
{
int c=30,d=40;
PRINT_VAL(c);
PRINT_VAL(d);
PRINT_VAL(x);
PRINT_VAL(y);
fun2(c,d);
}
fun2(int p,int q)
{
int e=50,f=60;
PRINT_VAL(e);
PRINT_VAL(f);
PRINT_VAL(p);
PRINT_VAL(q);
fun3(e,f);
}
fun3(int m,int n)
{
int g=70,h=80;
PRINT_VAL(g);
PRINT_VAL(h);
PRINT_VAL(m);
PRINT_VAL(n);
}
