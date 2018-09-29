#include "stdio.h"
#include "flv.h"
#include "string.h"

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
