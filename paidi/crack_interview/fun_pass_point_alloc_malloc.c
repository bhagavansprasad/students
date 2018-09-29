#include <stdio.h>
#include <stdlib.h>
int *allocate(int **);
int main()
{
 int *p;
 p = allocate(&p);
 *p = 20;
 printf("%d\n",*p);
}

int * allocate(int **ptr)
{
 *ptr = malloc(sizeof(4));
 return (int *)p;
}
