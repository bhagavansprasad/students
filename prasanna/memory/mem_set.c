/*
Description

The C library function void *memset(void *str, int c, size_t n) copies the character c (an unsigned char) to the first n characters of the string pointed to by the argument str.
Declaration

Following is the declaration for memset() function.

void *memset(void *str, int c, size_t n)

Parameters

    str -- This is pointer to the block of memory to fill.

    c -- This is the value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.

    n -- This is the number of bytes to be set to the value.

Return Value

This function returns a pointer to the memory area str.			

*/


#include<stdio.h>

void *mem_set(void *s, int c, size_t count)
{
	char *xs = (char*)s;
	while(count--)
		*xs++ = c;
	return s;
}
main()
{
	char str[30] = "This is first c program";
	mem_set(str,'$',5);
	printf(" values\n%c\n%c\n%c\n",str[0],str[2],str[4]);
	printf(" string :%s\n",str);
}


