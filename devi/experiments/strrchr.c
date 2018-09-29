#include <stdio.h>
#include <string.h>
main(void)
{
	char text[]="I learn through IndiaBix.com";
	char *ptr,c='i';
	ptr=strrchr(text,c);
	if(ptr)
	printf("%c\t%d\n", c,ptr-text);
	else
	printf("not found\n");
}
