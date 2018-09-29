#include <stdio.h>
char buf[300];
char *p1,*p2,*p3;
main()
{
	p1=amalloc(100);
	printf("p1 value is %u\n",p1);
	p1=amalloc(100);
	printf("p1 value is %u\n",p1);
	p1=amalloc(100);
	printf("p1 value is %u\n",p1);

}
