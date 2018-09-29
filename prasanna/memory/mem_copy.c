/*
Description

The C library function void *memcpy(void *str1, const void *str2, size_t n) copies n characters from memory area str2 to memory area str1.
Declaration

Following is the declaration for memcpy() function.

void *memcpy(void *str1, const void *str2, size_t n)

Parameters

    str1 -- This is pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.

    str2 -- This is pointer to the source of data to be copied, type-casted to a pointer of type void*.

    n -- This is the number of bytes to be copied.

Return Value

This function returns a pointer to destination, which is str1.
*/


#include<stdio.h>
#include<string.h>

void *mem_copy(void *dest, const void *src, size_t count)
{
	char *temp = (char *)dest;
	char *s = (char *)src;
	while(count--)
		*temp++ = *s++;
	return dest;

}

int main()
{	
	const char src[50] = "www.tutorialpoint.com";
	char dest[30];
	
	printf("Before mem_copy dest = %s\n",dest);
	mem_copy(dest,src,strlen(src)+1);
	printf("After mem_copy dest = %s\n",dest);
	return 0;
}

