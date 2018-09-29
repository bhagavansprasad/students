#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd=0,f=0,i;
	char buff[300];
	fd=open("t.c",0,O_RDONLY);
	for(i=0; ;i++)
	{
		f=read(fd,buff,300);
		buff[f]='\0';
		printf("%s\n",buff);
		if(f<300)
			break;
	}
	close(fd);
}
