#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

main()
{
	int i = 0, fd, rval;
	char *ch = "a";
	fd = open("balu", O_RDWR);
	while(1)
	{
		rval = write(fd, ch,1);
		printf("i value is : %d\n", i);
		if(rval != 1)
		{
			break;
		}
		i++;
	}
}
