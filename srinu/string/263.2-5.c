#include <stdio.h>
#include <string.h>
main()
{
	int i;
	char *str="tap";
	func(str);
}
void func(char *p)
{
	if(*p)
	{
		func(p+1);
		
			printf("%c",*p++);
		}
	}
