#include <string.h>
#include <stdio.h>
#include <fcntl.h>
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
	unsigned char buff[128];
	int retval=0;
int fd,i,l,tag,data,count=0;
	char buffer[1000];
	fd = open("sixth.flv", O_RDONLY);
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
	if((buff[0] != 'F') && (buff[1] != 'L') && (buff[2] != 'V'))
	{
		printf("this is not flv file");
		exit(0);
	}
	head.version   = buff[i];
	i++;
	head.is_video  = showbits(buff[i], 0, 1);
	head.reserved2 = showbits(buff[i], 1, 1);
	head.is_audio  = showbits(buff[i], 2, 1);
	head.reserved1 = showbits(buff[i], 3, 4);
	i++;
	head.offset = byte_fun(&buff[i] , 4);

//	printf("-----> FLV HEADER  <--------\n");
//	printf("type :%s\tversion :%d\taudiotag :%d\tvideotag :%d\tdata	sizeis %d\n",head.sign,head.version,head.is_audio,head.is_video,head.offset);

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
			printf("---->%d.%d data :%d\n", __LINE__, count++, data);

		//	printf("-----> FLV TAG HEADER  <--------\n");
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
		//	printf("<tag type=\"video\" timestamp=\"%d\" datasize=\"%d\" offset=\"%d\">\n",fbody.time_stamp,fbody.data_size,l);
			if(fvideo.codecId==7)
			{
				if(fvideo.frametype==1)
				{
				//	printf("\t<videoData codecID=\"AVC\" frameType=\"keyframe\"/>\n");
				}
				else
				{
				//	printf("\t<videodata codecID=\"AVC\" frameType=\"interframe\"/>\n");
				}
			}

			//printf("</tag>\n");
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
			
		
		//	printf("<tag type=\"audio\" timestamp=\"%d\" datasize=\"%d\" offset=\"%d\">\n",fbody.time_stamp,fbody.data_size,l);
			if(faudio.sound_format==10&&faudio.sound_size==1&&faudio.sound_type==1&&faudio.sound_rate==3)
			{
		//		printf("\t<audioData type=\"stereo\" size=\"16\" rate=\"44\" format=\"AAC\"/>\n");
			}
//printf("</tag>\n");
			l=lseek(fd,data-2,SEEK_CUR);
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





