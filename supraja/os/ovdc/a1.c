#include <stdio.h>
int main()
{
	printf("%d\n",getpid());
	for(;;)
	printf("%d\t",getpid());
}
