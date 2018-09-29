#include "stdio.h"

int my_function(int n, char ch)
{
	printf("%d. In function :%s\n", __LINE__, __FUNCTION__);
	printf("n :%d, ch :%c\n", n, ch);

	return 0;
}

main()
{
	int a = 10, ch = 'y';
	 int (*fp)(int, char);

	my_function(a, ch);

	fp = my_function;

	fp(a, ch);
}
