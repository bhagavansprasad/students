//#include "ab.h"
//static int local_foo(int x)
//{
//return x*x;
//}

int foo(int (*foop)(int x))
{
	return local_foo(x);
}

//int (*foop)(int) = local_foo;
