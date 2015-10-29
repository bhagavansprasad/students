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
	dump_flv_header(phead);
	strncpy(phead->signature, buff, SIGNATURE_LEN);
	phead->version = buff[3];
	flags = buff[4];

	phead->is_video = ((flags&(mask<<0))?1:0);
//	mask = 1;
	phead->is_audio = ((flags&(mask<<2))?1:0);
	for(i = 5; i <= 8; i++)
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
		printf("AUDIO     ----- audio tags are present\n");
	}
	else 
		printf("AUDIO     ----- audio tags are not present\n");
	if(1 == phead->is_video)
	{
		printf("VIDEO     ----- video tags are present\n");
	}
	else
		printf("VIDEO     ----- video tags are not present\n");
	printf("OFFSET    ----- %d\n\n\n",phead->offset);
}

void parse_flv_tag(char *buff, int len, struct flv_tag *thead)
{
	unsigned char flags = 0;
	
	unsigned int mask = 1,n, offset = 0;

	unsigned int i,converted_val=0,j; 

	bzero(thead, sizeof(struct flv_tag_header));
	dump_flv_tag(thead);
	for(i = 0; i < 4; i++)
	{
		n = buff[i];
		converted_val+= offset_value(n);
	}
	thead.prev_tag_size = converted_val;
	converted_val = 0;
	n=buff[i];
	converted_val = offset_value(n);
	if(converted_val == 8)
	thead.tag_size.audio = converted_val;

	for(j=0;j<3;j++)
	{
		n = buff[i++];
		converted_val = offset_value(n);
	}
	thead.data_size = converted_val;


}

void dump_flv_tag(struct flv_tag *thead)
{

	printf("Prev_tag_size         ----- %d\n",thead->prev_tag_size);
	printf("Tag_type              ----- %d\n",thead->tag_type);
	printf("Data_size             ----- %d\n",thead->data_size);
	printf("Time_stamp            ----- %d\n",thead->time_stamp);
	printf("Time_stamp_extended   ----- %d\n",thead->time_stamp_extended);
}
