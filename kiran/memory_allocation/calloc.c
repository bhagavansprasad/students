#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int *str;
	str = calloc(10,sizeof(char));
	if(str == NULL)
	{
		printf("request memory is not allocated\n");
	}
	else
	{
		*str = 400;
	}
	printf("allocated memory size is ---->  %d\n",(int)sizeof(str));
	printf("alocated memory content  ---->  %d\n",*str);
	free(str);
	printf("size after free ----> %d\n");
}
