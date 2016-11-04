#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
void abc()
{
	printf("pipe empty,i can do anything now\n");
	sleep(1);
}
main()
{
	int pid,p[2];
	struct stat pinfo;
	char buff[10];

	pipe(p);
	pid = fork();
	if(pid != 0)
	{
		sleep(5);
		write(p[1],"hello,world",12);
		printf("parent exiting\n");
	}
	else
	{
		for(;;)
		{
			fstat(p[0],&pinfo);
			if(pinfo.st_size == 0)
				abc();
			else
			{
				read(p[0],buff,12);
				printf("buff : %s\n",buff);
				printf("child exiting\n");
			}
		}
	}
}
