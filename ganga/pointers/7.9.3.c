#include <stdio.h>

main()
{
	char *p = malloc(20);

	printf("--> address of p is %p\n", &p);
	printf("--> value of p is %p %p\n", p, p + 2);
	printf("--> size of p is %d\n", sizeof(p));
	printf("--> size of *p is %d\n", sizeof(malloc(20)));

	strcpy(p, "gvhmagvANetworavdsvdcasgdvcjs djh ks");
	p[1] = 'u';
	printf("%s\n", p);
	printf("--> address of p is %p\n", &p);
	printf("--> value of p is %p\n", p);
	printf("--> size of p is %d\n", sizeof(p));
}

