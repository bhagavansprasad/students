#include <stdio.h>
#define SIZE_OF_STACK \
	register int sp asm ("sp");\
	register int ebp asm ("ebp");\
	printf("size of stack : %d\n",ebp-sp);\

main()
{
	//int a=10,b=20;
	//printf("main a %u\n",&a);
	//printf("main b %u\n",&b);
	fun1(10,20);


 /*SIZE_OF_STACK
printf("ebp value :%u\n",ebp);
printf("sp value :%u\n",sp);*/
}
void fun1(int a,int b)
{
	int e=10,f=20;
	//printf("fun1 f %u\n",&f);
	//printf("fun1 e %u\n",&e);
	//printf("argv1fun1 c %u\n",&c);
	//printf("argv1fun1 d %u\n",&d);
SIZE_OF_STACK;

printf("ebp value :%u\n",ebp);
printf("sp value :%u\n",sp);
}
