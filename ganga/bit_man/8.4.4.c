#include <stdio.h>

main()
{
	int a = 10001;
	a = swapevenoddbits(a);
	printf("%d\n", a);
}

int swapevenoddbits(int n)
{
	int result;
	result = (n ^ 0xF);
}
