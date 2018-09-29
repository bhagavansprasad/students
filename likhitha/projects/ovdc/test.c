#include <stdio.h>

main(int argc, char *argv[])
{
	int delay = 0;
	int i = 0;

	delay = atoi(argv[1]);

	printf("pid : %d\n", getpid());
	for (i = 1;  ;i++)
	{
		if (i % 99999999 == 0)
		{
			printf("pid : %d\n", getpid());
			sleep(delay);
			i = 1;
		}
	}
}
