#include <stdio.h>
#define SIZE_OF_STACK 
	register int sp asm ("sp");
	register int ebp asm ("ebp");


void fun1(int a,int b);
void main()
{
	fun1(10,20);
}
void fun1(int a,int b)
{
	int e=10,f=20;
	SIZE_OF_STACK;
  printf("ebp value :%u\n",ebp);
  printf("sp value :%u\n",sp);
}
