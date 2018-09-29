#include<stdio.h>

#define TOGGLE(n,p) ((1 << p) ^ n)
main()
{
int p;

p=TOGGLE(20,1);
printf("%d\n",p);
}


/* set bit using macrose*/
/*#define set(n,p) ((1 << p) | n)
main()
{
int p;
p=set(10,0);
printf("%d\n",p);
p=set(20,1);
printf("%d\n",p);
}*/
