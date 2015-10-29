#include "stdio.h"
main()
{
	FILE *ptr;
	char i;
	ptr=fopen("zzz.c","r");
	while((fgetc(ptr))!=EOF)
		printf("%c",i);
}
