#include <stdio.h>
#include <stdlib.h>
#define CHARPTR char*
typedef char* chaptr;
int main()
{
	CHARPTR c1,c2;
	chaptr c3,c4;
	printf("c1 %d, c2 %d, c3 %d, c4 %d\n", sizeof(c1), sizeof(c2), sizeof(c3),
	sizeof(c4));
	return 0;
}
