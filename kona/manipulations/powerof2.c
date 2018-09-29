#include <stdio.h>
main()
{
	unsigned n=1024;
	if(n&&!(n&(n-1)))
	printf("%d is power of 2\n",n);
	else
	printf("%d is not power of 2\n",n);

}
