#include <stdio.h>

extern **environ;

main()
{
	int i;

	for( i = 0 ; environ[i] ; i++)
		printf("environ[%d]->%s\n",i,environ[i]);
}
