#include <stdio.h>
#include <string.h>
#include "defs.h"


<<<<<<< HEAD
int read_file_head(int fd,char *buff,int len)
{
	int r = 0;
	r = read(fd,buff,len);
	return r;
}
void parsing_flv_head(char *buff,int len,struct file_head *fhead)
{
unsigned char flag = 0;
	bzero(fhead,sizeof(struct file_head));
	strncpy(fhead->SIGN,buff,3);
	fhead->version=buff[3];
	flag=buff[4];
	unsigned int mask=1;
	fhead->is_video=((flag&mask<<0)?1:0);
	fhead->is_audio=((flag&mask<<2)?1:0);
	fhead->off_set=buff[8];
}
void dump_list(struct file_head *fhead)
{
	printf("SIGNATURE::%s ==\n",fhead->SIGN);
	printf("version::%d ==\n",fhead->version);
		if(fhead->is_video==1)
		{
			printf(" video tag is present \n");
		}
		else
			printf(" video tag is not present \n");
	
	if(fhead->is_audio==1)
	{
		printf(" audio tag is present \n");
	}
	else
	{
		printf(" audio tag is not  present \n");
	}
	
	printf(" off_set %d \n",fhead->off_set);
=======
int read_file_head(int fd,unsigned char *buff,int len)
{
	int retval = 0;

	retval = read(fd, buff, len);

	return retval;
}

void parsing_flv_head(unsigned char *buff,int len,struct file_head *fhead)
{
	unsigned char flag = 0;
	unsigned int mask=1;

	bzero(fhead, sizeof(struct file_head));
	strncpy(fhead->signature, buff, 3);
	fhead->signature[3] = '\0';

	fhead->version = buff[3];
	flag = buff[4];

	fhead->is_video = ((flag & (mask << 0)) ? 1 : 0);
	fhead->is_audio = ((flag & (mask << 2)) ? 1 : 0);
	fhead->off_set  = buff[8];
}

void dump_list(struct file_head *fhead)
{
	printf("signature :%s\n", fhead->signature);
	printf("version   :%d\n", fhead->version);

	printf("Is audio  :%s\n", (fhead->is_audio ? "Yes" : "No"));
	printf("Is video  :%s\n", (fhead->is_video ? "Yes" : "No"));

	printf("off_set   :%d \n", fhead->off_set);
>>>>>>> 20d0cfd64d72678856fd795924cc44b2e7c782f4
}




