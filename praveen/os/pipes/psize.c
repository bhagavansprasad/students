#include <stdio.h>
#include <fcntl.h>
main()
{
	int fd,i,retval;
	char c = 'a';
	fd = open("pipe",O_RDWR);
	for (i = 0;;i++)
	{
		printf("the value of i is : %d\n",i+1);
		retval = write(fd,&c,1);
		if (retval != 1)
		{
		printf("write sys call is failed");
		break;

		}
	}
		
	
}

