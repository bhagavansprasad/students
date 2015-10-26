#include"stdio.h"
#include "a_string.h"
int main()
{
	char a[]="The wolf of wall street",*b;
	b=a_strrchr(a,'l');
	if(b)
	printf("the first occurence of \"l\" in string \"%s\" on reverse is at \"%s\"\n",a,b);
	else
	printf("The character is not available in given string\n");
	return 0;
}
