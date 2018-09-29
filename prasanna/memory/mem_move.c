/*

Description

The C library function void *memmove(void *str1, const void *str2, size_t n) copies n characters from str2 to str1, but for overlapping memory blocks, memmove() is a safer approach than memcpy().
Declaration

Following is the declaration for memmove() function.

void *memmove(void *str1, const void *str2, size_t n)

Parameters

    str1 -- This is pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.

    str2 -- This is pointer to the source of data to be copied, type-casted to a pointer of type void*.

    n -- This is the number of bytes to be copied.

Return Value

This function returns a pointer to destination, which is str1

*/

#include<stdio.h>
#include<string.h>

void *mem_move(void *dest, const void *src, size_t count)
{
	char *tmp, *s;
	if(dest <= src)
	{
		tmp = (char *)dest;
		  s = (char *)src;
		while(count--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = (char *)dest + count;
		  s = (char *)src + count;
		while(count--)
			*--tmp = *--s;
	}
	return dest;

}

int main()
{
	char dest[] = "DELL";
	const char src[] = "NewString";
	
	printf("Before mem_move dest  = %s\n src = %s\n",dest,src);
	mem_move(dest,src,3);
	printf("After mem_move dest = %s\n src = %s\n",dest,src);
	return 0;
}
