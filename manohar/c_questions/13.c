#include <stdio.h>
union test1
{
float a;
int d;
int b;
char c;
};
struct test2
{
float i;
int a,c;
char d;
};
union test1 t1;
struct test2 t2;

int main()
{
printf("union size-->%d, Structure Size-->%d\n",sizeof(t1),sizeof(t2));
}

