#include <stdio.h>
extern int i = 10;// warning 'i' initialized and declared 'extern' [enabled
//by default]
int main()
{
	printf("%d", i);
	return 0;
}


// o/p: 10
