#include <stdio.h>

int main(int argc, char *argv[])  
{
	int i = 0;

	printf("argc :%d\n", argc);

	for (i = 0; i < argc; i++)
		printf("i :%d, argv[%d] :%s\n", i, i, argv[i]);
#if 0
	if( argc == 2 )
	{
		printf("The argument supplied is %s\n", argv[1]);
	}
	else if( argc > 2 )
	{
		printf("Too many arguments supplied.\n");
	}
	else
	{
		printf("One argument expected.\n");
	}
#endif
}
