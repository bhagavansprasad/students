#include <stdio.h>
main()
{
	char const *str="bcd";
	const char *str1="abcd";

	char* const p = 'a';
	char ch = 'i';
	//p = &ch;
	printf("str1++ = %c\n", p);
	p++;
    printf("str1++ = %c\n", p);

	printf("str1 = %u\n", str1);
	str1++;
	printf("str1++ = %u\n", str1);
	

	printf("str = %u str = %s\n", str,str);
	str++;
	str[2]='h';
	printf("str = %u str= %s\n", str,str);
}
