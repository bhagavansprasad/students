#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *str;
	str = malloc( 20 * sizeof(char) );
	if( str == NULL )
	{
		printf("Couldn't able to allocate requested memory\n");
	}
	else
	{
		strcpy( str,"AURA NETWORKS");
	}
	printf("memory size --->   %d bytes\n",(int)sizeof(str));
	printf("Dynamically allocated memory content ---->  %s\n", str );
	str = realloc(str,100*sizeof(char));
	if( str == NULL )
	{
		printf("Couldn't able to allocate requested memory\n");
	}
	else
	{
		strcpy( str,"space is extended upto 100 characters");
	}
	printf("resized memory size ---> %d\n",(int)sizeof(str));
	printf("Resized memory : %s\n", str );
	free(str);
}


