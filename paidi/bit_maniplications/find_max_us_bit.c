#include <stdio.h>
main()
{
int a=20,b=100;
    int c = a - b;
    int k = (c >> 31) & 0x1;
    int max = a - k * c;
	printf("%d\n",max);
}
