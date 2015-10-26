#include<stdio.h>
void fun1(int,int);
void fun2(int,int);
void fun3(int,int);
main()
{
int a=10,b=20;
printf(" a:%d b:%d\n",a,b);
printf("main a:%u main b:%u\n",&a,&b);
fun1(a,b);
}
void fun1(int x, int y)
{
int a1=1,b1=2;
printf("a1 :%d b1:%d\n",a1,b1);
printf("fun1 a1:%u fun1 a2:%u\n",&a1,&b1);
printf("formal arguments in fun1 a : %u b:%u\n",&x,&y);
fun2(a1,b1);
}
void fun2(int x1, int y1)
{
int a2=3,b2=4,m;
printf("a2 :%d b2:%d\n",a2,b2);
printf(" m : %u\n",&m);
printf("fun2 a1:%u fun2 a2:%u\n",&a2,&b2);
printf("formal arguments in fun2 a : %u b:%u\n",&x1,&y1);
fun3(a2,b2);
}
void fun3(int x2, int y2)
{
int a3=5,b3=6;
printf("a3 :%d b3:%d\n",a3,b3);
printf("fun3 a3:%u fun3 a3:%u\n",&a3,&b3);
printf("formal arguments in fun3 a : %u b:%u\n",&x2,&y2);
}
