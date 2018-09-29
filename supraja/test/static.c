#include <stdio.h>
int func(int);
main()
{
	static int a=10,t;
	printf("%d\n",a);
  t=	func(a);
	printf("%d\n",t);
}
int func(int a)
{
	a++;
	return a;
}

