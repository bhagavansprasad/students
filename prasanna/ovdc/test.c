#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

main()
{
	int i;

	printf("-->pid :%d\n", getpid());
	for (i = 0; ;i++)
	{
		if (i%999999999 == 0)
			sleep(1);
	}
}
