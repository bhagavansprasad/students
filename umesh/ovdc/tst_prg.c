#include <stdio.h>
main()
{	
	int i = 0,j = 0;
//	printf("pid1 = %d\n",getpid());
	for(;;)
	{
		for(j = 0; j <= 10000000; j++)
		{
			if( j % 9999999999999999 == 0)
			{
				j = 1;
				printf("pid2 = %d\n",getpid());
				sleep(1);
			}
		}
	}
}

