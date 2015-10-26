
#define FUN_STACK_USAGE  \
	register int sp asm ("sp"); \
	register int ebp asm ("ebp"); \
	printf("stack size :%d\n", ebp-sp);\

int display1(int x, int y, int z)
{
	int a = 10;
	int b = 10;
	int c = 10;
	int d = 10;

	int e = 10;
	int f = 10;
	int g = 10;
	int h = 10;

	int i = 10;
	int j = 10;
	int k = 10;
	int l = 10;
	
	int m = 10;
	int n = 10;
	int o = 10;
	int p = 10;

	int q = 10;

#if 0

	register int d1sp asm ("sp");
	register int d1ebp asm ("ebp");

#endif

	FUN_STACK_USAGE;

	printf("ebp          %u\n", ebp);
	printf("sp           %u\n", sp);

}

main()
{
	display1(10, 20, 30);
}
