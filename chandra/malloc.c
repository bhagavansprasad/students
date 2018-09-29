#include<stdio.h>
main()
{
	char *ptr=malloc(10);
	char *str=malloc(10);
	char *array=malloc(10);
	printf("ptr:%u\n", ptr);
	printf("str:%u\n", str);
	printf("array:%u\n", array);
}
