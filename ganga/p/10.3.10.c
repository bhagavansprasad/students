#include<stdio.h>
union a{
int i;
char c[10];
}b;
main()
{
int j;
b.i=300;
for(j=0;j<sizeof(int);j++)
printf("%d\n",b.c[j]);
}
