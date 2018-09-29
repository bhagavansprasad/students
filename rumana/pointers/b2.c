#include<stdio.h>
void fun(int **);
main()
{
int *j;
fun(&j);
printf("%u\n",j);

}
void fun(int **k)
{
int a=10;
*k=&a;
printf("%u\n",*k);
}
