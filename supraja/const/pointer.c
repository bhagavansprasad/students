#include <stdio.h>
main()
{
 const int a=10,b=20;
	 int  *p;
	p=&a;
	p=&b;
	printf("%d\n",*p);
}
