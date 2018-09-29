#include<stdio.h>
void fun(int);
main()
{
int a[3]={10,20,30};
fun(a[1]);

}
void fun(int b)
{
printf("%d",b);
}
