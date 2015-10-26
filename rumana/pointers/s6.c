#include<stdio.h>
float *fun(float *);
main()
{
float p=23.5,*q;
q=&p;
printf("%u\n",q);
q=fun(&p);
printf("%u\n",q);
}
float *fun(float *r)
{
printf("%f\n",*r);
r=r+1;
return(r);
}
