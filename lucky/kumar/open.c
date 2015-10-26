#include<stdio.h> 
void perror(const  char *__s);
#include<errno.h>
#include <fcntl.h>
int main()
{
	int fd=0;
	fd=open("m.txt",0,O_RDONLY);
	if(fd<0)
		perror();
	exit();
}
