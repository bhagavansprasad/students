#include <stdio.h>
#include "a_string.h"
int main()
{
	char dest[]="RamKrishna",src[]="Vamsh",*p;
	printf("Before concat\nstring dest --> %s\nstring src --> %s\n",dest,src);
	p = a_strcat(dest,src);
	printf("After concat\nstring dest --> %s\nstring src --> %s\n",p,src);
	return 0;
}
