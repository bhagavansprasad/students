#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include<math.h>
#include<stdlib.h>
#include <sys/types.h>
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
	unsigned char buff[128];
	int retval=0;
	int fd,i,l,tag,data;
	char buffer[1000];
	fd = open("video.flv", O_RDONLY);
	if(fd == -1)
	{
		printf("failed to open\n");
		exit(0);
	}


	retval = read(fd, buff,9);
	if(retval == -1)
	{
		printf("read fail");
		exit(0);
	}

	for (i = 0; i < 3; i++)
	{
		head.sign[i]=buff[i];
		head.sign[3] = '\0';
	}
	head.version   = buff[i];
	i++;
	head.is_video  = showbits(buff[i], 0, 1);
	head.reserved2 = showbits(buff[i], 1, 1);
	head.is_audio  = showbits(buff[i], 2, 1);
	head.reserved1 = showbits(buff[i], 3, 4);
	i++;
	head.offset = byte_fun(&buff[i] , 4);

	printf("-----> FLV HEADER  <--------\n");
	printf("type :%s\n",head.sign);
	printf("version  :%d\n",head.version);
	printf("audiotag :%d\n",head.is_audio);
	printf("videotag :%d\n",head.is_video);
	printf("data size is :%d\n",head.offset);
	while(1)

	{
		retval=read(fd, buff, 15);
		fbody.tag_size   = 	byte_fun(&buff[0] , 4);

		if(retval == -1 && read == 0)
		{
			perror("tag error  \n");
			exit(1);
		}
		fbody.tag_type   = showbits(buff[4],0 ,5 );
		fbody.filter     = showbits(buff[4],5 ,1 );
		fbody.reserved   = showbits(buff[4],6 ,2 );
		fbody.data_size  = byte_fun(&buff[5], 3);
		fbody.time_stamp = byte_fun(&buff[8],3);
		fbody.timest_ext = buff[11];
		fbody.streamId   = byte_fun( &buff[12], 3);
		tag = fbody.tag_type;
		data = fbody.data_size;
		printf("-----> FLV TAG HEADER  <--------\n");
		printf("tag size      %d\n", fbody.tag_size);
		printf("tag type      %d\n", fbody.tag_type);
		printf("filter        %d\n", fbody.filter);
		printf("reserved      %d\n", fbody.reserved);
		printf("data size     %d\n", fbody.data_size);
		printf("time stamp    %d\n", fbody.time_stamp);
		printf("time stamp ex %d\n", fbody.timest_ext);
		printf("Stream ID     %d\n", fbody.streamId);


		if(tag==9)
		{
			retval=read(fd, buff,2 );
			if(retval == -1 && read == 0)
			{
				perror("tag error  \n");
				exit(1);
			}

			fvideo.codecId = showbits(buff[0],0,4);
			fvideo.frametype = showbits(buff[0],4,4);
			fvideo.avcpackettype= byte_fun(&buff[1],1);

			printf("---->flv video<-----\n");
			printf("frametype   %d\n",fvideo.frametype);
			printf("codecId     %d\n",fvideo.codecId);
			printf("avcpackettype%d\n",fvideo.avcpackettype);
			l=lseek(fd,data-2,SEEK_CUR);
		}
		else if (tag == 8)
		{
			retval=read(fd, buff,2 );
			if(retval == -1 && read == 0)
			{
				perror("tag error  \n");
				exit(1);
			}

			faudio.sound_type = showbits(buff[0],0,1);
			faudio.sound_size = showbits(buff[0],1,1);
			faudio.sound_rate = showbits(buff[0],2,2);
			faudio.sound_format = showbits(buff[0],4,4);
			faudio.aacpacket_type = byte_fun(&buff[1],1);
			printf("---->flv audio<------\n");
			printf("soundformat   %d\n",faudio.sound_format);
			printf("soundrate     %d\n",faudio.sound_rate);
			printf("soundsize     %d\n",faudio.sound_size);
			printf("soundtype     %d\n",faudio.sound_type);
			printf("aacpackettype %d\n",faudio.aacpacket_type);
			lseek(fd,data-2,SEEK_CUR);
		}
		else
		{
			l=lseek(fd,data,SEEK_CUR);
		}
		if(l>=20554726)
		{
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




