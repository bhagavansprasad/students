#include <stdio.h>

main( argc , argv , envp)
int argc;
char *argv[];
char *envp[];
{
	int i;
	for( i = 0 ; envp[i]; i++)
		printf("envp[%d]->%s\n",i,envp[i]);
}
