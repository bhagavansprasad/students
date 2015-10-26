#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

main()
{
	int pid;
	int p[2];
	struct stat pinfo;
	char buff[10];

	pipe(p);
	pid = fork();

	if( pid != 0)
	{
		sleep(5);
		write(p[1] , "Hello World ", 12);
		printf("parent process exiting \n" );
	}
	else
	{
		for(;;)
		{
			fstat(p[0] , &pinfo);
			if(pinfo.st_size == 0)
				abc();
			else
			{
				read( p[0] , buff , 12);
				printf("Buff : %s\n", buff);
				printf("child exiting \n");
				exit(0);
			}
		}
	}
}



abc()
{
	printf("pipe Empty , i can do any thing now \n");
	sleep(1);
}
