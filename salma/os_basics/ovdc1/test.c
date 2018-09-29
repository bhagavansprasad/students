#include<stdio.h>
main()
{
	unsigned int i = 1;
	printf("%d\t", getpid());

	for( ; ;i++)
	{
		if (i%99999999 == 0)
		{
			i = 1;
			sleep(1);
			printf("pid :%d\n", getpid());
		}

	}
}
