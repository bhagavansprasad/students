
#include "stdio.h"
#include "string.h"
#include "flv.h"

int read_flv_header(int fd, char *buff, int len)
{
	int r = 0;
	r = read(fd, buff, LEN);
	return 0;
}

void parse_flv_header(char *buff, int len,struct header *phead)
{
	unsigned char flags = 0;
	unsigned int mask = 1;

	bzero(phead, sizeof(struct header));
	strncpy(phead->signature, buff, 3);
	phead->version = buff[3];
	flags = buff[4];

	phead->is_video = (flags&(mask<<0)?1:0);

	phead->is_audio = (flags&(mask<<2)?1:0);
	phead->offset = buff[8];
}
void dump_flv_header(struct header *phead)
{
	printf("signature         :%s\n",phead->signature);
	printf("version           :%d\n",phead->version);
	if(phead->is_video = 1)
		printf("video is present\n");
	else
		printf("video is not present\n");
	if(phead->is_audio = 1)
		printf("audio is present\n");
	else
		printf("audio is not present\n");
	printf("offset            :%d\n",phead->offset);
}

int read_flv_tag(int fd, char *buff, int len)
{
	int r1 = 0;
	r1 = read(fd, buff, 15);
	return 0;
}

void parse_flv_tag(char *buff, int len, struct flv_tag *btag)
{
	int bits = 0, i = 0, j = 0, t = 0, d = 0, b = 0, s = 0;

	bzero(btag, sizeof(struct flv_tag));
	for(bits = 24, i = 0; i < 4; i++, bits-= 8)
	{
		b+= (buff[i] << bits);
	}
	btag->previous_tags = b;

	btag->Ttype = buff[4];
	for(bits = 16, i = 5; i < 8; i++, bits-= 8)
	{
		d+= (buff[i] << bits);
	}
	btag->datasize = d;
	for(bits = 16, i = 8; i < 11; i++, bits-= 8)
	{
		t+= (buff[i] << bits);
	}
	btag->timestamp = t;

	btag->tsExtended = buff[11];
	for(bits = 16,i = 12; i < 15; i++, bits-= 8)
	{
		s+= (buff[i] << bits);
	}
	btag->streamid = s;
}
void dump_flv_tag(struct flv_tag *btag)
{
	printf("prev tag           : %d\n", btag->previous_tags);
	if(btag->Ttype == 8)
	{
		printf("tag type is    : audio(8)\n");
	}
	else if(btag->Ttype == 9)
	{
		printf("tag type is    : video(9)\n");
	}
	else if(btag->Ttype == 18)
	{
		printf("tag tpye is      : scriptdata(18)\n");
	}
	printf("data size          :%d\n",btag->datasize);
	printf("time stamp         :%d\n",btag->timestamp);
	printf("timestamp entended :%d\n",btag->tsExtended);
	printf("stream ID          :%d\n",btag->streamid);
}
