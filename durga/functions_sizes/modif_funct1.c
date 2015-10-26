#include<stdio.h>
void fun1(int , int );
void fun2(int , int );
void fun3(int , int );
main()
{
	int a, b;
	register int spmain asm ("sp");
	register int ebpmain asm ("ebp");
	printf("ebpmain =%u\n", ebpmain);
	printf(" bmin()= %u\n",&b );
	printf(" amain()= %u\n",&a );
	printf("espmain=%u\n", spmain);

	fun1(a,b);
}

void fun1 (int c, int d)
{
	int l,m;
	int new = 0,new1=0;
	register int spfun1 asm ("sp");
	register int ebpfun1 asm ("ebp");
	//printf(" new2fun1()= %u\n",&new2 );
	printf("ebpfun1 =%u\n", ebpfun1);
	printf(" new1fun1()= %u\n",&new1 );
	printf(" newfun1()= %u\n",&new );
	printf(" mfun1()= %u\n",&m );
	printf(" lfun1()= %u\n",&l );
	printf(" cagrfun1()= %u\n",&c );
	printf("dargfun1()= %u\n",&d );
	printf("espdun1=%u\n", spfun1);
	fun2(l,m);
}

void fun2(int e, int f)
{
	int k,n;
	register int spfun2 asm ("sp");
	register int ebpfun2 asm ("ebp");
	printf("ebpfun1 =%u\n", ebpfun2);

	printf(" nfun2()= %u\n",&n );
 	printf(" kfun2()= %u\n",&k );

	printf(" eargfun2()= %u\n",&e );
	printf(" fargfun2()is= %u\n",&f );
	printf("espdun2=%p\n", spfun2);
	fun3(k, n);
}
void fun3(int g, int h)
{
	int o,p;
	register int spfun3 asm ("sp");
	register int ebpfun3 asm ("ebp");
	printf("ebpfun3 =%u\n", ebpfun3);
	printf("pfun3()= %u\n",&p );
	printf("ofun3()= %u\n",&o );
	printf(" gargfun3()= %u\n",&g );
	printf(" hargfun3()= %u\n",&h );
	printf("espfun3=%u\n", spfun3);

}
