#include "flv.h"

int read_flv_header(int, char *, int);
void parse_flv_header(char *, int, struct flv_file_header *);
void dump_flv_header(struct flv_file_header *);

int read_flv_header(int fd, char *buff, int len)
{
	int r = 0;
	r = read(fd,buff,len);
	return r;
}

void parse_flv_header(char *buff, int len, struct flv_file_header *phead)
{
	unsigned char flags = 0;

	bzero(phead, sizeof(struct flv_file_header));

	strncpy(phead->signature, buff, SIGNATURE_LEN);
	phead->version = atoi(buff[3]);

	flags = buff[4];
	
	/*if (flags's six bit is 1 ) then
		phead->is_video = 1;

	if (flags's eighth bit is 1 ) then
		phead->is_audio  = 1

	phead->offset = offset;*/
}


/*void dump_flv_header(struct flv_file_header *phead)
{
	
	printf("SIGNATURE ----- %s\n",s->signature);
	printf("VERSION   ----- %d\n",s->version);
	if(1 == s->is_audio)
	{
		printf("AUDIO ----- audio tags are present\n");
	}
	else 
		printf("AUDIO ----- audio tags are not present\n");
	if(1 == s->is_video)
	{
		printf("VIDEO ----- video tags are present\n");
	}
	else
		printf("VIDEO ----- video tags are not present\n");
	printf("OFFSET ----- %d\n",s->offset);
}*/
