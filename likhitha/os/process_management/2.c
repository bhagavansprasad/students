#include <stdio.h>
main()
{ 
	printf( " I am forking a child process \n ");
	fork();
	fork();
	fork();
	printf("%u\n",getpid());
}
