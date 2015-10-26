#include <stdio.h>

extern **environ;

main( argc , argv , envp)
int argc ;
char argv[];
char *envp[];
{
	int i;

	for( i = 0 ; envp[i] ; i++ )
		printf(" envp[%d]->%s\n",i,envp[i]);
	printf("\n");
	for( i = 0; environ[i] ; i++)
		printf("environ[%d]->%s\n", i, environ[i]);
}
