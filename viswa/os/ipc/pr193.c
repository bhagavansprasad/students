#include <stdio.h>

main()
{
	int p[2];
	pipe(p);
	printf("p[0]is :%d \tp[1] is : %d \n",p[0],p[1] );
}
