#include <stdio.h>
#include "a_string.h"
int main()
{
	char *p;
	char a[]="Aura Networks",b[100];
	p = a_strcpy(b,a);
	printf("String a -->%s\nString b -->%s\n",p,b);
	return 0;
}
