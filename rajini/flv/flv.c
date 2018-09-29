#include<stdio.h>
#include<string.h>
#include <unistd.h>
#include <fcntl.h>
<<<<<<< HEAD
#include"defs.h"

int read_file_head(int fd,char *buff,int len);
void parsing_flv_head(char *buff,int len,struct file_head *fhead);
void dump_list(struct file_head *fhead);
=======
#include "defs.h"
>>>>>>> 20d0cfd64d72678856fd795924cc44b2e7c782f4

main()
{
	struct file_head fhead;
<<<<<<< HEAD
	int fd,r,len=9;
	char buff[200];
	fd=open("sixth.flv",O_RDONLY,0777);

=======
	struct file_tag thead;
	int fd, retval, r1, len = 9;
	char buff[200];
	int curr_pos = 0;

	fd = open("sixth.flv",O_RDONLY,0777);
>>>>>>> 20d0cfd64d72678856fd795924cc44b2e7c782f4
	if(fd>=0)
		printf("opening file is successful\n");
	else
		printf("opening file is successful\n");
<<<<<<< HEAD

	r=read_file_head(fd,buff,len);
	parsing_flv_head(buff,len,&fhead);
	dump_list(&fhead);
=======
	
	printf("FLV HEADER INFORMATION\n\n");
	retval = read_file_head(fd, buff, len);
	parsing_flv_head(buff, len, &fhead);
	dump_list(&fhead);
	
	printf(" TAG 1 INFORMATION\n\n");

	curr_pos = lseek(fd, 0, SEEK_CUR);

	printf("curr pos  :%d\n", curr_pos);

	r1 = read_tag_head(fd, buff, 15);

	parsing_tag_head(buff,15,&thead);

	dump_tag_list(&thead);

	int size=9,i=0,j = 0;
	for(j = 2,i=0;  ;i++,j++)
	{
	printf("TAG %d INFORMATION \n\n",j);
		size+=15+(thead.data_size);
		lseek(fd,size,SEEK_SET);

		r1 = read_tag_head(fd, buff, 15);

		parsing_tag_head(buff,15,&thead);


		if(thead.tag_type!=8 && thead.tag_type!=9 && thead.tag_type!=18)
			break;

		dump_tag_list(&thead);

	}
>>>>>>> 20d0cfd64d72678856fd795924cc44b2e7c782f4
}
