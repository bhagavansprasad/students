#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "defs.h"
int main()
{
	int fd,wfd,r;
	struct students s1;
	wfd = open("student.db",O_CREAT|O_RDWR,0777);
	if(fd < 0)
	{
		printf("creating file is failed");
	}
	else
		printf("creating file is sucess\n");
	
	strcpy(s1.name,"ashok");
	s1.age = 100;
	s1.class = 3;
	
	r = write(wfd,&s1,sizeof(struct students));
	
	printf("size of struct=%d\n",sizeof(s1));
	printf("r = %d\n",r);
	
	close(r);
	close(wfd);
}
