#include <stdio.h>

int function1(int c,int d)
{
 int *pa=&d;
 int *pb=&c;
 printf("-----pa=%p\n",pa);
 printf("-----pb=%p\n",pb);
 
 int e=30,f=40;
 function2(e,f);

}
