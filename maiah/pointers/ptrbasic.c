#include <stdio.h>
main()
{
	int a=20;
	int *p=&a;
	int **pp=&p;
	printf("%d\n",a);
	printf("%u\n",&a);
	printf("%u\n",p);
	printf("%d\n",*p);
	printf("%u\n",&p);
	printf("%u\n",pp);
	printf("%u\n",*pp);
	printf("%d\n",**pp);
	printf("%d\n",***&pp);
	p++;
	printf("%u\n",p++);
}
