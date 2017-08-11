#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	char *str;
	char *s="rinju";
	printf("enter a name\n");
	str = (char *) malloc(20);
	gets(str);
	puts(s);
	//puts(str);
	printf("u have enter %s",str);
	free(str);
}
