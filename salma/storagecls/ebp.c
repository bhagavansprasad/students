#include<stdio.h>

#define STACK_SIZE \
	register int sp asm ("sp");\
	register int ebp asm ("ebp");\
	printf("stack size :%u\n",ebp-sp);\

#define PRINT(x) (printf(" %s    %u\n",#x,&x))

void function(int,int,int);
main()
{
	//	register int ebp asm ("ebp");
	int p=10,q=20;
	PRINT(q);
	PRINT(p);
	function(10,20,30);
	//printf("ebp ----->%u\n",ebp-4);
}
void function(int x,int y,int z)
{
	int a=1;
	int b=2;
	int c=3;
	int d=4;
	int *t;
	PRINT(d);
	PRINT(c);
	PRINT(b);
	PRINT(a);
	PRINT(x);
	PRINT(y);
	PRINT(z);
	STACK_SIZE;
	printf("ebp ----->%u\n",ebp);
	printf("ebp-1  -->%u\n",((int *)ebp)-3);

	t = ((int *)ebp)-3;
	printf("t      -->%u\n", t);
	printf("*t     -->%u\n", *t);

	printf("sp ----->%u\n",sp);
	//	printf("ebp  substracting by 12 gives local variable address D:----->%u\n",ebp-12);
	//	printf("ebp  adding  by 12 gives argument address address----- X:>%u\n",ebp+8);
	//	printf("ebp subtacting by 32 gives p address  P :>%u\n",ebp+34);
	// t = (ebp-4);
	//printf("d addr :%u\n",ebp-4);
	//printf("p addr:%u\n",ebp+24);
	//printf("%d\n",((int *)ebp-4));
	//printf("%d\n",*(ebp-4));
}
