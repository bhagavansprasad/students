#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *str;
	str = malloc(2*sizeof(char));
	if(str == NULL )
	{
		printf("Couldn't able to allocate requested memory\n");
	}
	else
	{
		strcpy( str,"AURA NETWORKS");
	}
	printf("size of created memory               ---->  %d\n",(int)sizeof(str));
	printf("Dynamically allocated memory content ---->  %s\n", str );
	free(str);
}
