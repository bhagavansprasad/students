#include<stdio.h>
main()
{
	int p[2], pid;
	pipe(p);
	pid = fork();

	//pipe(p);
	if( pid == 0)
		printf("in child p[0] %d  p[1] %d\n", p[0], p[1]);
	else 
		printf("in parent p[0] %d  p[1] %d\n", p[0], p[1]);
}
