#include <stdio.h>
#include <string.h>
void func(char *p);
main()
{
	char *str="doubtful";
	func(str);
}
void func(char *p)
{
	if(*p!='f')
	{
		printf("%c",*p);
		func(++p);
	}
}
