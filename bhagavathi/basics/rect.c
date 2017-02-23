#include<stdio.h>
main()
{
int l=19,b=7,a1,b1;
float r=98.6,pi=3.14,a2,b2;
/*rect*/
a1=l*b;
b1=(2*l+2*b);
/*circle*/
a2=pi*r*r;
b2=2*pi*r;
printf("area of rect=%d\n",a1);
printf("perimeter of rect=%d\n",b1);
printf("area of circle=%f\n",a2);
printf("area of circle=%f\n",b2);
}
