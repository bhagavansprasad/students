#include <stdio.h>
int main()
{
 float a=0.0f, b=1.0f, c=2.0f, d=0;
 float* aray[] = {&a, &b, &c};
 d = a + c;
 printf("d        :%f\n",d);
}
