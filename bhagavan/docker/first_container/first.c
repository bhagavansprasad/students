#include "stdio.h"

main(int argc, char *argv[])
{
	int count = 10;
	int i = 0;

	if (argc == 2)
		count = atoi(argv[1]);

	for (i = 1; i <= count; i++)
	{
		printf("My first docker container :%d\n", i);
		sleep(1);
	}
}
