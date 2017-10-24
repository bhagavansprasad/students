#include <stdio.h>

main()
{
	char *str = "ramesh";
	fun(str);
	printf("%s\n", str);
}

void fun(char *ptr)
{
	*ptr = "ganga";
}
