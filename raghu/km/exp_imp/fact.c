#include <linux/module.h>    // included for all kernel modules

int factorial(int n)
{
	int fact = 1;

	for (; n > 0; n--)
		fact *= n;

	return fact;
}

int is_prime(int n)
{
	return 0;
}


EXPORT_SYMBOL(factorial);
//EXPORT_SYMBOL(is_prime);
