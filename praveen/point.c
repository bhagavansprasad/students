#include <stdio.h>
main()
{
	static int a[]={0,1,2,3,4};
	static int *p[]={a,a+1,a+2,a+3,a+4};
	printf("%u\n%u\n%d\n",p,*p,*(*p));

}
