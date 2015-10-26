#include<stdio.h>
#include<stdlib.h>
union byte
{
int a;
char c[4];
};
union byte single;
main()
{
single.a=300;
printf("single.a=%u\n",single.a);
printf("single.c[0]=%u\n",single.c[0]);
printf("single.c[1]=%u\n",single.c[1]);
printf("single.c[2]=%u\n",single.c[2]);
printf("single.c[3]=%u\n",single.c[3]);
}


