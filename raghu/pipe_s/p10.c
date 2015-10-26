#include <stdio.h>
#include <stdlib.h>

main()
{
	int p[2],i=0,fd;
	char ch = 'a';
	pipe(p);
	while(1)
	{
		fd = write(p[1],&ch,1);
				printf("the value of i = %d\n",i);
				printf("--------> fd = %d\n",fd);
			if(fd != 1)
			{
				exit(0);
			}
	
			i++;
	}
}
