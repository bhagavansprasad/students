#include "flv.h"

int read_flv_header(int fd, char *buff, int len)
{
	int r = 0;
	r = read(fd,buff,len);
	return r;
}

void parse_flv_header(char *buff, int len, struct flv_file_header *phead)
{
	unsigned char flags = 0;
	unsigned int mask = 1,i,n, offset = 0;

	bzero(phead, sizeof(struct flv_file_header));
	strncpy(phead->signature, buff, SIGNATURE_LEN);
	phead->version = buff[3];
	flags = buff[4];

	phead->is_video = ((flags&(mask<<0))?1:0);
	mask = 1;
	phead->is_audio = ((flags&(mask<<2))?1:0);
	for(i = 5; i <= len-1; i++)
	{
		n = buff[i];
		offset+= offset_value(n);
	}
	phead->offset = offset;
}

void dump_flv_header(struct flv_file_header *phead)
{

	printf("SIGNATURE ----- %s\n",phead->signature);
	printf("VERSION   ----- %d\n",phead->version);
	if(1 == phead->is_audio)
	{
		printf("AUDIO     ----- audio tags are present in flv file header\n");
	}
	else 
		printf("AUDIO     ----- audio tags are not present in flv file header \n");
	if(1 == phead->is_video)
	{
		printf("VIDEO     ----- video tags are present in flv file header\n");
	}
	else
		printf("VIDEO     ----- video tags are not present in flv file header\n");
	printf("OFFSET    ----- %d\n",phead->offset);
}
