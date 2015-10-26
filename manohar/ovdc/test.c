#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
main()
{
	int i=0;
	while(1)
	{
		for(i=1;;i++)
		{
			if(i%999999999==0)
			{
			i=1;
			break;
			}
		}
		printf("pid----->%d",getpid());
		sleep(1);
		printf("\n");
	}

}



