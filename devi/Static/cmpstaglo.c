#include <stdio.h>
int a;//global var o/p=0
extern int b;
static char c;
static int i;
static float f;
static char *str;
int main()
{
printf("%d\n", a);
printf("%d\n", b);//undefined ref to b
printf("static values\t %d %d %f %s",c,i,f,str);//0 0 0.000000 (null)
return 0;
}
