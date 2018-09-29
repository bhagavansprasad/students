#include <stdio.h>
int main()
{
	int i=10;
	int *ptr = &i;
	printf( "%d,  %d\n",*(char*)ptr,*(char *)(ptr+1));
}
