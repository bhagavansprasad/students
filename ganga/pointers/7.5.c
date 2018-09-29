#include <stdio.h>

main()
{
	int a = 300;
	int *ip = &a;
	char *cp = &a;
	
	printf("--> a     :%d \n", a);
	printf("--> &a    : %p\n ", &a);
	printf("--> *&a   : %d\n ", *&a);
	
	printf("--> ip    : %p\n ", ip);
	printf("--> &ip   : %p\n ", &ip);
	printf("--> *ip   : %d\n ", *ip);
	printf("--> *&ip  : %p\n ", *&ip);
	printf("--> **&ip : %d\n ", **&ip);
	
	printf("--> cp    : %p\n ", cp);
	printf("--> &cp   : %p\n ", &cp);
	printf("--> *cp   : %d\n ", *cp);
	printf("--> *&cp  : %p\n ", *&cp);
	printf("--> **&cp : %d\n ", **&cp);
}
