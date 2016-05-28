#include <stdio.h>
#include <fcntl.h>
main()
{
	int p[2];
	pipe(p);
	printf("p[0] is : %d\t,p[1] is : %d\n",p[0],p[1]);
}
