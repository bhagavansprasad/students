#include <stdio.h>
void *amalloc(void );
char a[100];
main()
{
	void *p;
	char *s="aura networks";
	p=amalloc();
	p=s;
	printf("%s\n",(char *)p);
}
void *amalloc(void )
{
	return (void *)a;
}

