#include <stdio.h>
#include <string.h>
char arr[10];
void * amalloc(int size)
{
	void *p;
	p = arr;
	printf("%u\n",arr);
	return p;
}
main()
{
	char *cp;
	char str[10]="bangalore";
	cp =(char *)amalloc(10);
	printf("%u\n",cp);
	strcpy(cp,str);
	printf("----> cp is : %s\n",cp);
}
