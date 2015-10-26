#include <stdio.h>
#include <string.h>
char arr[10];
void * amalloc(int size)
{
	void *p;
	p = arr;
	return p;
}
main()
{
	char *cp;
	char str[10]="bangalore";
	cp =(char *)amalloc(10);
	strcpy(cp,str);
	printf("----> cp is : %s\n",cp);
}
