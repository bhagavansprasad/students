#include<stdio.h>
#include<string.h>
main()
{
	//char ch='s';
	char ch;
	printf("enter a char");
	ch = getc(stdin);
	putc(ch,stdout);
}
