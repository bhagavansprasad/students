#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include<stdlib.h>
#include <unistd.h>
#include "def.h"
int showbits(char , int , int );
int byte_fun(unsigned char * , int );
main()
{
	flv_header head;
	flv_body fbody;
	flv_audio faudio;
	flv_video fvideo;
	char buff[30000];
	int retval=0,wretval=0, count = 0;
	int fd,p,i,l,tag,data,fd1,fd2,a=1;
	fd = open("sixth.flv", O_RDONLY);
	if(fd == -1)
	{
		perror("failed to open\n");
		exit(0);
	}

	fd1 = open("audio.flv", O_WRONLY);
	fd2 = open("video.flv", O_WRONLY);


	retval = read(fd, buff,9);
	if(retval == -1)
	{
		printf("read fail");
		exit(0);
	}


	wretval=write(fd1 , buff,9);
	
	wretval=write(fd2 , buff,9);

	while(1)
	{
		retval=read(fd, &fbody.tag_size, 4);
		printf("-->%d. asked :%d, retval :%d\n", __LINE__, 4, retval);
		//fbody.tag_size   = 	byte_fun(&buff1[0] , 4);
		retval=read(fd, buff, 11);
		if(retval == -1 && read == 0)
		{
			perror("tag error  \n");
			exit(1);
		}
		printf("-->%d. asked :%d, retval :%d\n", __LINE__, 11, retval);

		fbody.tag_type   = showbits(buff[0],0 ,5 );
			fbody.data_size  = byte_fun(&buff[1], 3);
		
		tag = fbody.tag_type;
		data = fbody.data_size;
		printf("---->%d count %d data :%d\n", __LINE__, count++, data);
		printf ("tag %d\n",tag);
		if(a==2)
		{
			fvideo.vtag_size=fbody.tag_size;
			faudio.atag_size=fbody.tag_size;
		}
		a++;
		if(tag==9)
		{
			wretval=write(fd2, &fvideo.vtag_size,4);
			p=data+11;
			printf("-->p value %d\n", p);
			printf("---> prevtagsize before rev%x\n", p);
			fvideo.vtag_size=(((p<<24)|(p>>24))|((((p<<16)>>24)<<16)|(((p>>16)<<24)>>16)));
			printf("---> prevtagsize after rev %x\n", fvideo.vtag_size);
			wretval=write(fd2, buff, 11);
			retval=read(fd, buff, data);
			if(retval == -1 && read == 0)
			{
				perror("tag error  \n");
				exit(1);
			}
			printf("-->%d. asked :%d, retval :%d\n", __LINE__, data, retval);
					wretval=(fd2, buff, data);
			l=lseek(fd,0,SEEK_CUR);
			printf("video data = %d\n",data);
		}
	else if (tag == 8)
		{
			wretval=write(fd1, &faudio.atag_size,4);
			p=data+11;
			faudio.atag_size=(((p<<24)|(p>>24))|((((p<<16)>>24)<<16)|(((p>>16)<<24)>>16)));
			wretval=write(fd1, buff,11);
			retval=read(fd, buff, data);
			if(retval == -1 && read == 0)
			{
				perror("tag error  \n");
				exit(1);
			}
			printf("-->%d. asked :%d, retval :%d\n", __LINE__, data, retval);
			wretval=write(fd1,buff,data);
			l=lseek(fd,0,SEEK_CUR);

		}
		else if(tag==18) 
		{
			wretval = write(fd1, &fbody.tag_size, 4);
			wretval = write(fd1, buff, 11);
			wretval = write(fd2, &fbody.tag_size, 4);
			wretval = write(fd2, buff, 11);
			retval = read(fd, buff, data);
			printf("-->%d. asked :%d, retval :%d\n", __LINE__, data, retval);
			wretval = write(fd1, buff, data);
			wretval = write(fd2, buff, data);

			l=lseek(fd,0,SEEK_CUR);

		}	
	else
		{
			p=data+11;
			faudio.atag_size=(((p<<24)|(p>>24))|((((p<<16)>>24)<<16)|(((p>>16)<<24)>>16)));
			fvideo.vtag_size=(((p<<24)|(p>>24))|((((p<<16)>>24)<<16)|(((p>>16)<<24)>>16)));

			wretval = write(fd1, &faudio.atag_size, 4);
			wretval = write(fd1, buff, 11);
			wretval = write(fd2, &fvideo.vtag_size, 4);
			wretval = write(fd2, buff, 11);
			retval = read(fd, buff, data);
			printf("-->%d. asked :%d, retval :%d\n", __LINE__, data, retval);
			wretval = write(fd1, buff, data);
			wretval = write(fd2, buff, data);

			l=lseek(fd,0,SEEK_CUR);

		}	


	printf("seek = %d\n",l);

		if(l>=20554726)
		{
			printf("seek loop = %d\n",l);


		break;
		}


	}
}
int showbits(char val, int s, int n)
{
	int f_bit = 0;
	int i=0;
	int t = n + s;
	for(i = s; i < t; i++)
	{
		f_bit += val & (1<<i);
	}
	if(s != 0)
		f_bit = f_bit >> s;
	return f_bit;
}

int byte_fun(unsigned char *buffer, int k)
{
	int i=2,val=0,j=k;
	for(i=0; i<k; i++, j--)
	{
		val += buffer[i] << (8 *( j-1));
	}
	return val;
}






