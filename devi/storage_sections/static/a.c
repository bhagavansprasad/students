#include <stdio.h>
int foo(int (*foop)(int));
static int local_foo(int z)
{
return z*z;
}
int main(void)
{
	int (*foop)(int) = local_foo;
//	printf("foo(%d) = ",x);
//	printf("%d\n",x=foo((*foop)(x)));
//	printf("foop(%d) = ",x);
//	printf("%d\n",x=foop(x));
	x=foo((foop)(x));
	printf("%d\n",x);
	return 0;
}

