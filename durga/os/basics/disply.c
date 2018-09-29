#include<stdio.h>
#include<fcntl.h>
void disply(int pid)
{
	int r,fd,i, l = 10;
	char buf[10];
	fd = open("/proc/pid/stat", O_RDONLY);
	//for(i = 0; i<5; i++)
	//{
		while(1)
		{
			r = read( fd, buf, 10);
			printf("%s",buf);
			if(r < l)
				break;
		}
		printf("\n");
		sleep(2);
		lseek( fd, 0l, 0);
	//}
}
