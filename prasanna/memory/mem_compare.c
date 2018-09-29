/* 
Description

The C library function int memcmp(const void *str1, const void *str2, size_t n)) compares the first n bytes of memory area str1 and memory area str2.
Declaration

Following is the declaration for memcmp() function.

int memcmp(const void *str1, const void *str2, size_t n)

Parameters

    str1 -- This is the pointer to block of memory.

    str2 -- This is the pointer to block of memory.

    n -- This is the number of bytes to be compared.

Return Value

    if Return value if < 0 then it indicates str1 is less than str2

    if Return value if > 0 then it indicates str2 is less than str1

    if Return value if = 0 then it indicates str1 is equal to str2

*/

#include<stdio.h>
#include<string.h>

int mem_compare(const void *s1, const void *s2, size_t n)
{
	const unsigned char *str1,*str2;
	int res = 0;
	for(str1 = s1,str2 = s2; 0 < n; ++str1,++str2,n--)
		if((res = *str1 - *str2) != 0)
			break;
	return res;
}


int main()
{
	char str1[15];
	char str2[15];
	int ret;

	memcpy(str1,"abcdef",6);
	memcpy(str2,"ABCDEF",6);
	ret = mem_compare(str1,str2,5);
	if(ret > 0)
		printf("str1 is less than str2\n");
	else if(ret < 0)
		printf("str2 is less than str1\n");
	else
		printf("str1 is equal to str2\n");
	return 0;
}
