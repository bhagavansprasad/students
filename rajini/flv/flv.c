#include<stdio.h>
#include<string.h>
#include <unistd.h>
#include <fcntl.h>
#include"defs.h"

int read_file_head(int fd,char *buff,int len);
void parsing_flv_head(char *buff,int len,struct file_head *fhead);
void dump_list(struct file_head *fhead);

main()
{
	struct file_head fhead;
	int fd,r,len=9;
	char buff[200];
	fd=open("sixth.flv",O_RDONLY,0777);

	if(fd>=0)
		printf("opening file is successful\n");
	else
		printf("opening file is successful\n");

	r=read_file_head(fd,buff,len);
	parsing_flv_head(buff,len,&fhead);
	dump_list(&fhead);
}
