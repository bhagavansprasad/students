#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "defs.h"
int main()
{
	int rfd,r;
	struct students s1;

	rfd=open("student.db",O_RDONLY,0777);
	
	r=read(rfd,&s1,sizeof(s1));
	
	printf("student name = %s\n",s1.name);
	printf("student age = %d\n",s1.age);
	printf("student class = %d\n",s1.class);
	
	close(rfd);
}
