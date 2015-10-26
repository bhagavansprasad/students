#include "stdio.h"

#define PRINT_VAR(x)      (printf("%10s %10p %15lu\n", #x, x,  (unsigned long int)x))
#define PRINT_VAR_ADDR(x) (printf("%10s %10p %15lu\n", #x, &x, (unsigned long int)&x))

int function3(int arg1fun3, int arg2fun3)
{
	int gfun3 = 70, hfun3 = 80, ifun3 = 90, jfun3 = 100, kfun3 = 80, lfun3 = 200, mfun3 = 20, nfun3 = 30;
	register int spfun3 asm ("sp");
	register int ebpfun3 asm ("ebp");

	PRINT_VAR(ebpfun3);
	PRINT_VAR_ADDR(nfun3);
	PRINT_VAR_ADDR(mfun3);
	PRINT_VAR_ADDR(lfun3);
	PRINT_VAR_ADDR(kfun3);
	PRINT_VAR_ADDR(jfun3);
	PRINT_VAR_ADDR(ifun3);
	PRINT_VAR_ADDR(hfun3);
	PRINT_VAR_ADDR(gfun3);
	PRINT_VAR_ADDR(arg1fun3);
	PRINT_VAR_ADDR(arg2fun3);
	PRINT_VAR(spfun3);
}


int function2(int arg1fun2, int arg2fun2)
{
	int efun2 = 50, ffun2 = 60;
	register int spfun2 asm ("sp");
	register int ebpfun2 asm ("ebp");

	PRINT_VAR(ebpfun2);
	PRINT_VAR_ADDR(ffun2);
	PRINT_VAR_ADDR(efun2);
	PRINT_VAR_ADDR(arg1fun2);
	PRINT_VAR_ADDR(arg2fun2);
	PRINT_VAR(spfun2);
	
	function3(efun2, ffun2);
}

int function1(int arg1fun1, int arg2fun1)
{
	int cfun1 = 30, dfun1 = 40;
	register int spfun1 asm ("sp");
	register int ebpfun1 asm ("ebp");

	PRINT_VAR(ebpfun1);
	PRINT_VAR_ADDR(dfun1);
	PRINT_VAR_ADDR(cfun1);
	PRINT_VAR_ADDR(arg1fun1);
	PRINT_VAR_ADDR(arg2fun1);
	PRINT_VAR(spfun1);
	
	function2(cfun1, dfun1);
}

main()
{
	int amain = 10, bmain = 20;
	register int spmain asm ("sp");
	register int ebpmain asm ("ebp");

	PRINT_VAR(ebpmain);
	PRINT_VAR_ADDR(bmain);
	PRINT_VAR_ADDR(amain);
	PRINT_VAR(spmain);

	function1(amain, bmain);
#if 0

	DUMP(amain);
	DUMP(bmain);
	printf("%s\n", #amain);
#endif

}
