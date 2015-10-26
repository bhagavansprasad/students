#include <stdio.h>
extern int i;//Error: undefined reference to i
int main()
{
	printf("%d", i);
	return 0;
}
