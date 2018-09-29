#include"stdio.h"
#include "a_string.h"
int main()
{
	char a[]="The wolf of wall street",*b;
	b=a_strchr(a,'w');
	if(b)
	printf("the first occurence of \"w\" in string \"%s\" is at \"%s\"\n",a,b);
	else
	printf("The character is not available in given string\n");
	return 0;
}
