#include "stdio.h"
#include "fcntl.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "stdbool.h"
#include "defs.h"

#define SCRIPT_DATA   18
#define VIDEO_TAG_DATA 9
#define AUDIO_TAG_DATA 8

int fd1, fd2, offset;
int main()
{
	int fd = 0;

	fd = open("key.flv", O_RDONLY, 0744);
	printf("fd value is :%d\n", fd);

	read_flv_header(fd);
	dump_flv_header();
	read_flv_body(fd);

	return 0;    
}

int read_flv_body(int fd)
{
	int len = 0, i = 0, n = 0, taglen = 0;
	char buffer[1024] = " ";

	while(1)
	{
		int rd = 0;
		n = read_flv_tags(fd);

		switch (n)
		{
			case SCRIPT_DATA:
				dump_flv_tag();
				//read_script_data_tag();
				//dump_script_data_tag();
				break;

			case VIDEO_TAG_DATA:
				dump_flv_tag();
				//rd = read_video_tag(fd);
				//dump_video_tag();
				break;

				/*	case AUDIO_TAG_DATA:
					dump_flv_tag();
				//rd = read_audio_tag(fd);
				//dump_audio_tag();
				break;*/
		}

		i++;
		if(n == 1)
			exit(0);

		taglen = (tdata.data_size - rd);

		offset = lseek(fd, taglen, SEEK_CUR);
	}
	return 0;
}

int read_flv_header(int fd)
{
	int n = 0, i = 0, retval = 0; 
	char buff[10]; 
	char *cp;
	int fd1;
	int wretval; 
	retval = read(fd, buff, 9);

	strncpy(hdata.sign, buff, 3);
	hdata.sign[3] = '\0';

	hdata.version = buff[3];
	hdata.res = buff[4];

	hdata.vedio_bit = (hdata.res & 1);

	hdata.audio_bit = ((hdata.res >> 2) & 1);

	cp = (char *)&hdata.data_offset;

	for (i = 8 ; i >= 5 ; i--)
	{
		*cp = buff[i];
		cp++;
	}


	return 0;
}

int dump_flv_header()
{
	int wretval = 0, len = 0;
	char buffer[1024] = " ";

	len += sprintf(buffer, "<type:\"%s\" ", hdata.sign);

	len +=  sprintf(buffer + len, "hasVedio:\"%s\" ", (hdata.vedio_bit ? "true" : "false"));

	len += sprintf(buffer + len, "hasAudio:\"%s\" ", (hdata.audio_bit ? "true" : "false"));

	len += sprintf(buffer + len, "version:\"%d\">\n", hdata.version);

	printf("buffer is :%s\n", buffer);


	return 0;
}

int read_flv_tags(int fd)
{
	static temp=0;
	int a = 0, c = 0, i = 0, n = 0, wval = 0, wretval = 0, retval = 0, mask = 0x1F; 
	char buff[1024];
	int fd1 = 0;
	char *p;
	char *dp;
	char *tp; 
	char *sp = (char *)&tdata.stream_id;
	int tsfd = 0, tslen = 0;
	char buff1[200000] = " ";

	retval = read(fd, buff1, 4);

	if(retval < 4)
		return 1;

	else
	{
		p = (char *)&tdata.previoustag;

		for (i = 3 ; i >= 0 ; i--)
		{
			*p = buff1[i];
			p++;
		}
		printf("prev %d\n",tdata.previoustag);

		retval = read(fd, buff, 1);

		a = buff[0];
		printf(" a:%d\n", a);
		n = ((a >> 6) & 3);
		printf(" n:%d\n", n);
		tdata.reserved = n;

		tdata.filter = ((a >> 5) & 1);

		c = a & mask;
		printf(" c:%d\n", c);
		tdata.tag_type = c;

		retval = read(fd, buff, 3);


		tdata.data_size = 0;
		dp = (char *)&tdata.data_size;

		for(i = 2; i >= 0; i--)
		{
			*dp = buff[i];		
			dp++;
		}

		retval = read(fd, buff, 3);

		tdata.timestamp = 0; 
		tp= (char *)&tdata.timestamp;

		for(i = 2; i >= 0; i--)
		{
			*tp = buff[i];
			tp++;
		}

		retval = read(fd, buff, 1);


		tdata.timestamp_extended = buff[0];

		retval = read(fd, buff, 3);


		for(i = 2; i >= 0; i--)
		{
			*sp = buff[i];
			sp++;
		}

	}

	return tdata.tag_type;
}

int dump_flv_tag()
{
	int wretval = 0, tslen = 0 , len = 0;
	static a = 1;
	extern  offset; 
	char buffer[1024] = " ";
	char tempbuff[1024] = " ";

	len += sprintf(buffer+len , "<tag%d>\n", a);

	switch(tdata.tag_type)
	{
		case 18 :
			len += sprintf(buffer + len, "<tagtype:\"scriptdata\" ");
			break;

		case 9 :
			len += sprintf(buffer + len, "<tagtype:\"video\" ");
			break;

		case 8 :
			len += sprintf(buffer + len, "<tagtype:\"audio\" ");
			break;
	}

	len += sprintf(buffer + len, "timestamp:\"%d\" ", tdata.timestamp);
	len += sprintf(buffer + len, "datasize:\"%d\" ", tdata.data_size);
	len += sprintf(buffer + len, "offset:\"%d\">", (hdata.data_offset+4));

	printf("%s\n", buffer);

	hdata.data_offset = offset;

	fflush(stdout);
	a++;

	return 0;
}
/*int vrd;
char buff[10];
int read_video_tag(int fd)
{
	int i, fd1 = 0, fd2 = 0, retval = 0,wretval = 0, mask = 0xF;
	int p;
	char *cp;
	char buff1[1024] = " ";

	vrd += read(fd, buff, 1);

	p = buff[0];
	vdata.frame_type = ((p >> 4) & mask);

	
	vdata.codecID = (p & mask);

	if(vdata.codecID == 7)
	{
		vrd += read(fd, buff, 1);
		vdata.AVCpackettype = buff[0];
	}

	if(vdata.codecID == 7)
	{
		vrd += read(fd, buff, 3);

		cp = (char *)&vdata.compositiontime;
		for(i = 0; i <= 2; i++)
		{
			*cp = buff[i];
			cp++;
		}
	}

	if(tdata.filter == 1);

	else
		videotagbody(fd);

	return vrd;
}

int videotagbody(int fd)
{
	int wretval, fd1, vrd;
	if(vdata.frame_type == 5)
		vrd += read(fd, buff, 1);
	else
	{
		if(vdata.codecID == 2);

		if(vdata.codecID == 3);

		if(vdata.codecID == 4);

		if(vdata.codecID == 5);

		if(vdata.codecID == 6);

		if(vdata.codecID == 7)
			AVCVIDEOPACKET(fd);
	}
	wretval = write(fd1, buff, vrd);

	return vrd;
}

int AVCVIDEOPACKET(int fd)
{
	if(vdata.AVCpackettype == 0)

		if(vdata.AVCpackettype == 1)

			return 0;
}
int dump_video_tag()
{
	int len = 0, wretval = 0;
	char buffer[1024] = " ";
	extern timestamp;

	switch(vdata.codecID)
	{
		case 2 :
			len += sprintf(buffer + len, "<codecID:\"sorenson H.263\" ");
			break;

		case 3 :
			len += sprintf(buffer + len, "<codecID:\"Screen video\" ");
			break;

		case 4 :
			len += sprintf(buffer + len, "<codecID:\"On2 VP6\" ");
			break;

		case 5 :
			len += sprintf(buffer + len, "<codecID:\"On2 VP6 with alpha channel\" ");
			break;

		case 6 :
			len += sprintf(buffer + len, "<codecID:\"Screen video version2\" ");
			break;

		case 7 :
			len += sprintf(buffer + len, "<codecID:\"AVC\" ");
			break;
	}

	switch(vdata.frame_type)
	{
		case 1 :
			len += sprintf(buffer + len, "FrameType:\"keyframe\">\n");
			break;

		case 2 :
			len += sprintf(buffer + len, "FrameType:\"inter frame\">\n");
			break;

		case 3 :
			len += sprintf(buffer + len, "FrameType:\"disposal inter frame\">\n");
			break;

		case 4 :
			len += sprintf(buffer + len, "FrameType:\"generated keyframe\">\n");
			break;

		case 5 :
			len += sprintf(buffer + len, "FrameType:\"video info/command frame\">\n ");
			break;
	}

	//wretval = write(fd3, buffer, len);

	printf("%s\n", buffer);

	return 0;
}*/
