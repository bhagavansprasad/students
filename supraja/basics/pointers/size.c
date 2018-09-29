#include<stdio.h>
int main()
{
int a=300;
int *pa;
pa=&a;
int **ppa;
ppa=&pa;
printf("%d",**ppa);
**ppa=20;
printf("\n%d\n",**ppa);
}
