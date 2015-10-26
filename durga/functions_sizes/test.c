#include<stdio.h>
void fun(int, int);

//register int spmain asm ("sp");
//register int ebpmain asm ("ebp");
main()
{
	register int spmain asm ("sp");
	register int ebpmain asm ("ebp");
	int a=10, b =20;
	//printf("spmain= %u\n", spmain);
	printf("amain= %u\n", &a);
	printf("bmain= %u\n", &b);
	printf("ebpmain= %u\n", ebpmain);

	fun(a, b);
}

void fun(int c, int d)
{
	register int spfun asm ("sp");
	register int ebpfun asm ("ebp");
	printf("ebpfun= %u\n", ebpfun);
	printf("cfun= %u\n", &c);
	printf("dfun= %u\n", &d);
	int * ptr = ebpfun;
	printf("content in pointer is %u\n", ptr+8);
//	ptr = ptr+12;
//	printf("next value from base point is %u\n", ptr-4);
//	ptr = ptr - 4;
//	printf("next value from the address of the pointer%u\n", ptr+1);
}
