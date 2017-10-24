#include <stdio.h>
#include <stdlib.h>
int flag = 0;
char buf[100];
void * amalloc(int );
void afree(void* );
main()
{
	char*p1, *p2;
		p1 = amalloc(100);
	printf("amalloc return address:%p\n", p1);
	p2 = amalloc(100);
	printf("amalloc return value: %p\n", p2);
   afree(p1);
	p2 = amalloc(100);
	printf("amalloc return value: %p\n", p2);
}
void* amalloc(int size)
{
	if (flag == 0)
	{
		flag = 1;
		return buf;
	}
	else 
		return NULL;
}
void afree(void* p)
{
		flag = 0;
}
