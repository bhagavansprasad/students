#include<stdio.h>
void areaperi(int,float *,float *);
main()
{
int r=5;
float a,p;
areaperi(r,&a,&p);
printf("%f\n",a);
printf("%f\n",p);
}
void areaperi(int r,float *ar,float *pr)
{
*ar=3.14*r*r;
*pr=2*3.14*r;
}
