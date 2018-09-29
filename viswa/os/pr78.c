#include <stdio.h>

main()
{
	extern **environ;
	int i;
	for( i =0 ; environ[i] ; i++)
		printf("environ[%d]->%s\n", i ,environ[i]);
}
